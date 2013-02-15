/*
** Cpu.c for Cpu.c in /home/bigup/prog/svn-projet-pitek/C++/vm_abstract/
**
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
**
** Started on  Wed Feb 16 11:33:23 2011 dimitri doyen
// Last update Sun Feb 20 22:33:13 2011 anthony reboul
*/

#include <sstream>
#include "Cpu.hh"
#include "Operand.hh"

Cpu::Cpu() {}

Cpu::~Cpu() {}

e_err		Cpu::execute_line(std::string command, std::string arg)
{
  //Tests de debug :
  //std::cout << "Commande: " << command << std::endl;
  //std::cout << "Arguments: " << arg << std::endl;

  if (command == "pop")
    return (pop());
  else if (command == "dump")
    {
      dump();
      return (NONE);
    }
  else if (command == "assert")
    return (assert(arg));
  else if (command == "push")
    return (push(arg));
  else if (command == "add")
    return (add());
  else if (command == "sub")
    return (sub());
  else if (command == "mul")
    return (mul());
  else if (command == "div")
    return (div());
  else if (command == "mod")
    return (mod());
  else if (command == "print")
    return (print());
  return (NONE);
}

std::string	Cpu::found_value(size_t pos, std::string arg)
{
  std::string	value = "";
  int		i = 0;

  while (arg[pos] != ')' && arg[pos] != '\0' && arg[pos] != ';'
	 && arg[pos] >= '0' && arg[pos] <= '9')
    {
      value[i] = arg[pos];
      pos++;
      i++;
    }
  return (value);
}

e_err		Cpu::push(std::string arg)
{
  size_t	pos;

  if ((pos = arg.find("int8")) != std::string::npos)
    my_list.push_front(createOperand(Int8, found_value(pos + 5, arg)));
  else if ((pos = arg.find("int16")) != std::string::npos)
    my_list.push_front(createOperand(Int16, found_value(pos + 6, arg)));
  else if ((pos = arg.find("int32")) != std::string::npos)
    my_list.push_front(createOperand(Int32, found_value(pos + 6, arg)));
  else if ((pos = arg.find("float")) != std::string::npos)
    my_list.push_front(createOperand(Float, found_value(pos + 6, arg)));
  else if ((pos = arg.find("double")) != std::string::npos)
    my_list.push_front(createOperand(Double, found_value(pos + 6, arg)));
  else
    return (PUSH);
  return (NONE);
}

e_err		Cpu::pop()
{
  if (my_list.empty())
    return (POP);
  my_list.pop_front();
  return (NONE);
}

void		Cpu::dump()
{
  for (std::list<IOperand *>::iterator it = my_list.begin(); it != my_list.end(); it++)
    std::cout << (*it)->toString() << std::endl;
}

e_err		Cpu::assert(std::string arg)
{
  std::list<IOperand *>::iterator it = my_list.begin();
  std::string	value;

  value = (*it)->toString();
  if (value == arg)
    return (NONE);
  return (ASSERT);
}

e_err		Cpu::add()
{
  IOperand	*first;
  IOperand	*second;
  IOperand	*n;
  std::list<IOperand *>::iterator it = my_list.begin();

  if (my_list.size() < 2)
    return (ADD);
  first = *it;
  it++;
  second = *it;
  n = (*first) + (*second);
  my_list.pop_front();
  my_list.pop_front();
  my_list.push_front(n);
  return (NONE);
}

e_err		Cpu::sub()
{
  IOperand	*first;
  IOperand	*second;
  IOperand	*n;
  std::list<IOperand *>::iterator it = my_list.begin();

  if (my_list.size() < 2)
    return (SUB);
  first = *it;
  it++;
  second = *it;
  n = (*first) - (*second);
  my_list.pop_front();
  my_list.pop_front();
  my_list.push_front(n);
  return (NONE);
}

e_err		Cpu::mul()
{
  IOperand	*first;
  IOperand	*second;
  IOperand	*n;
  std::list<IOperand *>::iterator it = my_list.begin();

  if (my_list.size() < 2)
    return (MUL);
  first = *it;
  it++;
  second = *it;
  n = (*first) * (*second);
  my_list.pop_front();
  my_list.pop_front();
  my_list.push_front(n);
  return (NONE);
}

e_err		Cpu::div()
{
  IOperand	*first;
  IOperand	*second;
  IOperand	*n;
  std::list<IOperand *>::iterator it = my_list.begin();

  if (my_list.size() < 2)
    return (DIV);
  first = *it;
  it++;
  second = *it;
  n = (*first) / (*second);
  my_list.pop_front();
  my_list.pop_front();
  my_list.push_front(n);
  return (NONE);
}

e_err		Cpu::mod()
{
  IOperand	*first;
  IOperand	*second;
  IOperand	*n;
  std::list<IOperand *>::iterator it = my_list.begin();

  if (my_list.size() < 2)
    return (MOD);
  first = *it;
  it++;
  second = *it;
  n = (*first) % (*second);
  my_list.pop_front();
  my_list.pop_front();
  my_list.push_front(n);
  return (NONE);
}

e_err		Cpu::print()
{
  std::list<IOperand *>::iterator it = my_list.begin();

  if (my_list.empty())
    return (PRINT);
  if ((*it)->getType() != Int8)
    return (PRINT);
  std::cout << (*it)->toString() << std::endl;
  return (NONE);
}


typedef struct		s_functab
{
  eOperandType		type;
  IOperand *	(Cpu::*f)(const std::string &);
}			t_functab;

IOperand	*Cpu::createOperand(eOperandType type, const std::string &value)
{
  int		i;

  t_functab	Tab[6] = {
    {Int8, &Cpu::createInt8},
    {Int16, &Cpu::createInt16},
    {Int32, &Cpu::createInt32},
    {Float, &Cpu::createFloat},
    {Double, &Cpu::createDouble},
    {End, NULL}
  };

  if (value == "")
    return (NULL);
  for (i = 0; Tab[i].type != End; i++)
    {
      if (Tab[i].type == type)
	return ((this->*(Tab[i].f))(value));
    }
  return (NULL);
}

IOperand *	Cpu::createInt8(const std::string &value)
{
  IOperand	*OperandeInt8 = new Operand<int8_t>(value, Int8);

  return (OperandeInt8);
}

IOperand *	Cpu::createInt16(const std::string &value)
{
  IOperand	*OperandeInt16 = new Operand<int16_t>(value, Int16);

  return (OperandeInt16);
}

IOperand *	Cpu::createInt32(const std::string &value)
{
  IOperand	*OperandeInt32 = new Operand<int32_t>(value, Int32);

  return (OperandeInt32);
}

IOperand *	Cpu::createFloat(const std::string &value)
{
  IOperand	*OperandeFloat = new Operand<float>(value, Float);

  return (OperandeFloat);
}

IOperand *	Cpu::createDouble(const std::string &value)
{
  IOperand	*OperandeDouble = new Operand<double>(value, Double);

  return (OperandeDouble);
}
