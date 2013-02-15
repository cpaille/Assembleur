//
// IOperand.hpp for abstractvm in /home/audrade/work/abstractvm-2014-caille_c
// 
// Made by cailleux carole
// Login   <caille_c@epitech.net>
// 
// Started on  Mon Feb 14 18:08:24 2011 cailleux carole
// Last update Sat Feb 19 18:55:43 2011 raphael chambily
//

#ifndef			__OPERANDS_HPP__
# define		__OPERANDS_HPP__

#include <string>
#include <iostream>
#include <sstream>
#include "IOperand.hpp"
#include "exception.hpp"

template <typename T>
class			Operand : public IOperand
{
public:
  Operand(std::string val, eOperandType type);
  ~Operand();

  Operand	*clone() const;
  std::string const& toString() const;
  int		getPrecision() const;
  eOperandType	getType() const;
  T		getValue() const;

  IOperand *operator+(const IOperand &rhs) const;
  IOperand *operator-(const IOperand &rhs) const;
  IOperand *operator*(const IOperand &rhs) const;
  IOperand *operator/(const IOperand &rhs) const;
  IOperand *operator%(const IOperand &rhs) const;

private:
  eOperandType		type;
  std::string		str;
  T			value;

};

template <typename T>
Operand<T>::Operand(std::string val, eOperandType type)
  : type(type), str(val)
{
  std::stringstream	a;

  a.str(val);
  a >> this->value; 
}

template <typename T>
Operand<T>::~Operand()
{
}

template <typename T>
Operand<T>*		Operand<T>::clone() const
{
  return (new Operand<T>(this->toString(), this->type));
}

template <typename T>
std::string const&	Operand<T>::toString() const
{
  return (this->str);
}

template <typename T>
int			Operand<T>::getPrecision() const
{
  return (static_cast<int>(this->type));
}

template <typename T>
eOperandType		Operand<T>::getType() const
{
  return (this->type);
}

template <typename T>
T			Operand<T>::getValue() const
{
  return (this->value);
}

template <typename T>
IOperand*		Operand<T>::operator+(const IOperand &rhs) const
{
  Operand	*res;
  double	tmp;
  std::stringstream	a;

  a.str(rhs.toString());
  a >> tmp;
  res = (rhs.getPrecision() > this->getPrecision() ? 
	 static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = this->value + tmp;
  a.clear();
  a << res->value;
  res->str = a.str();
  return (res);
}

template <typename T>
IOperand*		Operand<T>::operator-(const IOperand &rhs) const
{
  Operand	*res;
  double	tmp;
  std::stringstream	a;

  a.str(rhs.toString());
  a >> tmp;
  res = (rhs.getPrecision() > this->getPrecision() ? 
	 static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = this->value - tmp;
  a.clear();
  a << res->value;
  res->str = a.str();
  return (res);
}

template <typename T>
IOperand*		Operand<T>::operator*(const IOperand &rhs) const
{
  Operand	*res;
  double	tmp;
  std::stringstream	a;

  a.str(rhs.toString());
  a >> tmp;
  res = (rhs.getPrecision() > this->getPrecision() ? 
	 static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = this->value * tmp;
  a.clear();
  a << res->value;
  res->str = a.str();
  return (res);
}

template <typename T>
IOperand*		Operand<T>::operator/(const IOperand &rhs) const
{
  Operand	*res;
  double	tmp;
  std::stringstream	a;

  a.str(rhs.toString());
  a >> tmp;
  if (tmp == 0.0)
    throw myException("Division by 0");
  res = (rhs.getPrecision() > this->getPrecision() ? 
	 static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = this->value / tmp;
  a.clear();
  a << res->value;
  res->str = a.str();
  return (res);
}

template <>
inline IOperand*		Operand<double>::operator%(const IOperand &) const
{
  throw myException("Modulo by decimal");
};

template <>
inline IOperand*		Operand<float>::operator%(const IOperand &) const
{
  throw myException("Modulo by decimal");
}

template <typename T>
IOperand*		Operand<T>::operator%(const IOperand &rhs) const
{
  Operand	*res;
  int		tmp;
  std::stringstream	a;

  a.str(rhs.toString());
  a >> tmp;
  if (tmp == 0)
    throw myException("Modulo by 0");
  if (rhs.getType() == FLOAT || rhs.getType() == DOUBLE)
    throw myException("Modulo by decimal");
  res = (rhs.getPrecision() > this->getPrecision() ? 
	 static_cast<const Operand &>(rhs).clone() : this->clone());
  res->value = this->value % tmp;
  a.clear();
  a << res->value;
  res->str = a.str();
  return (res);
}

#endif
