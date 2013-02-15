//
// VmStack.cpp for Abstract Vm in /home/chambi_r//.ssh/abstractvm-2014-caille_c
// 
// Made by raphael chambily
// Login   <chambi_r@epitech.net>
// 
// Started on  Tue Feb 15 12:10:08 2011 raphael chambily
// Last update Sat Feb 19 21:42:32 2011 raphael chambily
//

#include <string>
#include <iterator>
#include <sys/types.h>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "VmStack.hpp"
#include "exception.hpp"

VmStack::VmStack()
{
  this->funcs["pop"] = &VmStack::pop;
  this->funcs["dump"] = &VmStack::dump;
  this->funcs["add"] = &VmStack::add;
  this->funcs["sub"] = &VmStack::sub;
  this->funcs["mul"] = &VmStack::mul;
  this->funcs["div"] = &VmStack::div;
  this->funcs["mod"] = &VmStack::mod;
  this->funcs["print"] = &VmStack::print;
  this->funcs_types["int8"] = &VmStack::create_int8;
  this->funcs_types["int16"] = &VmStack::create_int16;
  this->funcs_types["int32"] = &VmStack::create_int32;
  this->funcs_types["float"] = &VmStack::create_float;
  this->funcs_types["double"] = &VmStack::create_double;
}

VmStack::~VmStack()
{
  while (this->_values.size() != 0)
  {
    delete this->_values.front();
    this->_values.pop_front();
  }
}
 
static void		check_characters(const char *str, int have_point)
{
  const char		*correct = "0123456789";
  int			is_decimal;
  int			i;
  int			point_found;

  i = 0;
  point_found = 0;
  if (str[i] && str[i] == '-')
    i++;
  while (str[i])
    {
      is_decimal = 0;
      for (int j = 0 ; correct[j] ; j++)
	{
	  if (str[i] == correct[j])
	    {
	      is_decimal = 1;
	      break ;
	    }
	}
      if (!is_decimal)
	{
	  if (have_point && !point_found && str[i] == '.' && str[i + 1]
	      && i != 0 && str[i - 1] != '-')
	    point_found = 1;
	  else
	    throw myException("Syntax error");
	}
      i++;
    }
  if (have_point && !point_found)
    throw myException("The value must be decimal");
}

// ;; dans le fichier n'arrete pas la lecture

IOperand		*VmStack::get_operand(std::string const& str)
{
  IOperand		*res;
  size_t		fparenthesis;
  size_t		lparenthesis;
  std::string		value;
  std::string		type;

  res = NULL;
  fparenthesis = str.find_first_of('(');
  lparenthesis = str.find_last_of(')');
  if (!fparenthesis || !lparenthesis || fparenthesis > lparenthesis ||
      lparenthesis == fparenthesis + 1)
    throw myException("Incorrect syntax");
  type = str.substr(0, fparenthesis);
  value = str.substr(fparenthesis + 1, lparenthesis - fparenthesis - 1);
  if (type == "float" || type == "double")
    check_characters(value.c_str(), 1);
  else
    check_characters(value.c_str(), 0);
  if (this->funcs_types.find(type) == this->funcs_types.end())
    throw myException("The specified type doesn't exist");
  res = (this->*funcs_types[type])(value);
  return (res);
}

IOperand	*VmStack::create_int8(std::string const& value)
{
  return (new Operand<int16_t>(value, INT8));
}

IOperand	*VmStack::create_int16(std::string const& value)
{
  return (new Operand<int16_t>(value, INT16));
}

IOperand	*VmStack::create_int32(std::string const& value)
{
  return (new Operand<int32_t>(value, INT32));
}

IOperand	*VmStack::create_float(std::string const& value)
{
  return (new Operand<float>(value, FLOAT));
}

IOperand	*VmStack::create_double(std::string const& value)
{
  if (value.find('.') == value.npos)
    throw myException("Double without decimals");
  return (new Operand<double>(value, DOUBLE));
}

void		VmStack::func_call(std::string s1, std::string s2)
{
  std::string	type;
  IOperand	*operand;

  if (s1 == "exit")
    return ;
  else if (s1 == "push")
    {
      operand = this->get_operand(s2);
      this->push(operand);
    }
  else if (s1 == "assert")
    {
      operand = this->get_operand(s2);
      this->assert(operand);
      delete operand;
    }
  else if (this->funcs.find(s1) == this->funcs.end())
    throw myException("Incorrect instruction");
  else
    (this->*funcs[s1])();
}

void		VmStack::push(IOperand *val)
{
  this->_values.push_front(val);
}

void		VmStack::pop()
{
  if (this->_values.empty())
    throw myException("'pop' instruction on an empty stack");
  delete this->_values.front();
  this->_values.pop_front();
}

void		VmStack::dump()
{
  std::deque<IOperand *>::iterator	it;

  for (it = this->_values.begin() ; it != this->_values.end() ; ++it)
    std::cout << (*it)->toString() << std::endl;
}

void		VmStack::assert(IOperand *val)
{
  if (this->_values.size() < 1)
  {
    delete val;
    throw myException("Nothing to check");
  }
  if (val->getPrecision() == this->_values.front()->getPrecision() &&
      val->toString() == this->_values.front()->toString())
    return ;
  {
    delete val;
    throw myException("Assertion Failed");
  }
}

void		VmStack::add()
{
  IOperand	*op1;
  IOperand	*op2;
  IOperand	*res;

  if (this->_values.size() < 2)
    throw myException("Calculation without two parameters in stack");
  op1 = this->_values.front();
  this->_values.pop_front();
  op2 = this->_values.front();
  this->_values.pop_front();
  res = *op1 + *op2;
  this->_values.push_front(res);
  delete op1;
  delete op2;
}

void		VmStack::sub()
{
  IOperand	*op1;
  IOperand	*op2;
  IOperand	*res;

  if (this->_values.size() < 2)
    throw myException("Calculation without two parameters in stack");
  op1 = this->_values.front();
  this->_values.pop_front();
  op2 = this->_values.front();
  this->_values.pop_front();
  res = *op2 - *op1;
  this->_values.push_front(res);
  delete op1;
  delete op2;
}

void		VmStack::mul()
{
  IOperand	*op1;
  IOperand	*op2;
  IOperand	*res;

  if (this->_values.size() < 2)
    throw myException("Calculation without two parameters in stack");
  op1 = this->_values.front();
  this->_values.pop_front();
  op2 = this->_values.front();
  this->_values.pop_front();
  res = *op1 * *op2;
  this->_values.push_front(res);
  delete op1;
  delete op2;
}

void		VmStack::div()
{
  IOperand	*op1;
  IOperand	*op2;
  IOperand	*res;

  if (this->_values.size() < 2)
    throw myException("Calculation without two parameters in stack");
  op1 = this->_values.front();
  this->_values.pop_front();
  op2 = this->_values.front();
  this->_values.pop_front();
  res = *op2 / *op1;
  this->_values.push_front(res);
  delete op1;
  delete op2;
}

void		VmStack::mod()
{
  IOperand	*op1;
  IOperand	*op2;
  IOperand	*res;

  if (this->_values.size() < 2)
    throw myException("Calculation without two parameters in stack");
  op1 = this->_values.front();
  this->_values.pop_front();
  op2 = this->_values.front();
  this->_values.pop_front();
  res = *op2 % *op1;
  this->_values.push_front(res);
  delete op1;
  delete op2;
}

void		VmStack::print()
{
  std::stringstream	ss;
  short			tmp;
  char			c;

  if (this->_values.size() < 1)
    throw myException("Nothing to print");
  if (this->_values.front()->getType() == INT8)
  {
    ss.str(this->_values.front()->toString());
    ss >> tmp;
    c = tmp;
    std::cout << c << std::endl;
  }
  else
    throw myException("Top of the stack isn't an Int8");
}
