/*
** Operand.c for Operand.c in /home/bigup/prog/svn-projet-pitek/C++/vm_abstract/
**
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
**
** Started on  Thu Feb 17 12:38:13 2011 dimitri doyen
<<<<<<< .mine
// Last update Sun Feb 20 23:40:08 2011 dimitri doyen
=======
// Last update Sun Feb 20 19:12:24 2011 anthony reboul
>>>>>>> .r85
*/

#include <sstream>
#include "Operand.hh"

template<typename T>
Operand<T>::Operand(std::string op, eOperandType type)
{
  _soperand = op;
  _type = type;
  _toperand = dynamic_cast<T>(op);
}

template<typename T>
std::string  const	&Operand<T>::toString() const
{
  return (_soperand);
}

template<typename T>
int			Operand<T>::getPrecision() const
{
  return (getType());
}

template<typename T>
eOperandType		Operand<T>::getType() const
{
  return (_type);
}

template<typename T>
eOperandType		Operand<T>::select_type(eOperandType first, eOperandType second) const
{
  if (first > second)
    return (first);
  return (second);
}

template<typename T>
IOperand		*Operand<T>::operator+(const IOperand &rhs) const
{
  Operand               *first;
  Operand               *second;
  eOperandType          new_type;

  first = this;
  second = rhs;
  new_type = select_type(first->getType(), second->getType());
  if (new_type == Int8)
    return (createOperand(new_type, convint8_t(first->toString()) + 
			  convint8_t(second->toString())));
  if (new_type == Int16)
    return (createOperand(new_type, convint16_t(first->toString()) + 
			  convint16_t(second->toString())));
  if (new_type == Int32)
    return (createOperand(new_type, convint32_t(first->toString()) + 
			  convint32_t(second->toString())));
  if (new_type == Float)
    return (createOperand(new_type, convinfloat(first->toString()) + 
			  convinfloat(second->toString())));
  if (new_type == Double)
    return (createOperand(new_type, convindouble(first->toString()) + 
			  convindouble(second->toString())));
  return (NULL);
}

template<typename T>
IOperand		*Operand<T>::operator-(const IOperand &rhs) const
{
  Operand               first;
  Operand               second;
  eOperandType          new_type;

  first = *this;
  second = rhs;
  new_type = select_type(first.getType(), second.getType());
  if (new_type == Int8)
    return (createOperand(new_type, convint8_t(first.toString()) - 
			  convint8_t(second.toString())));
  if (new_type == Int16)
    return (createOperand(new_type, convint16_t(first.toString()) - 
			  convint16_t(second.toString())));
  if (new_type == Int32)
    return (createOperand(new_type, convint32_t(first.toString()) - 
			  convint32_t(second.toString())));
  if (new_type == Float)
    return (createOperand(new_type, convinfloat(first.toString()) - 
			  convinfloat(second.toString())));
  if (new_type == Double)
    return (createOperand(new_type, convindouble(first.toString()) - 
			  convindouble(second.toString())));
  return (NULL);
}

template<typename T>
IOperand		*Operand<T>::operator/(const IOperand &rhs) const
{  
  Operand               first;
  Operand               second;
  eOperandType          new_type;

  first = *this;
  second = rhs;
  new_type = select_type(first.getType(), second.getType());
  if (new_type == Int8)
    return (createOperand(new_type, convint8_t(first.toString()) / 
			  convint8_t(second.toString())));
  if (new_type == Int16)
    return (createOperand(new_type, convint16_t(first.toString()) /
			  convint16_t(second.toString())));
  if (new_type == Int32)
    return (createOperand(new_type, convint32_t(first.toString()) / 
			  convint32_t(second.toString())));
  if (new_type == Float)
    return (createOperand(new_type, convinfloat(first.toString()) / 
			  convinfloat(second.toString())));
  if (new_type == Double)
    return (createOperand(new_type, convindouble(first.toString()) / 
			  convindouble(second.toString())));
  return (NULL);
}

template<typename T>
IOperand		*Operand<T>::operator%(const IOperand &rhs) const
{
  Operand               first;
  Operand               second;
  eOperandType          new_type;

  first = *this;
  second = rhs;
  new_type = select_type(first.getType(), second.getType());
  if (new_type == Int8)
    return (createOperand(new_type, convint8_t(first.toString()) % 
			  convint8_t(second.toString())));
  if (new_type == Int16)
    return (createOperand(new_type, convint16_t(first.toString()) % 
			  convint16_t(second.toString())));
  if (new_type == Int32)
    return (createOperand(new_type, convint32_t(first.toString()) % 
			  convint32_t(second.toString())));
  if (new_type == Float)
    return (createOperand(new_type, convinfloat(first.toString()) % 
			  convinfloat(second.toString())));
  if (new_type == Double)
    return (createOperand(new_type, convindouble(first.toString()) % 
			  convindouble(second.toString())));
  return (NULL);
}

template<typename T>
IOperand		*Operand<T>::operator*(const IOperand &rhs) const
{
  Operand               first;
  Operand               second;
  eOperandType          new_type;

  first = *this;
  second = rhs;
  new_type = select_type(first.getType(), second.getType());
  if (new_type == Int8)
    return (createOperand(new_type, convint8_t(first.toString()) * 
			  convint8_t(second.toString())));
  if (new_type == Int16)
    return (createOperand(new_type, convint16_t(first.toString()) * 
			  convint16_t(second.toString())));
  if (new_type == Int32)
    return (createOperand(new_type, convint32_t(first.toString()) * 
			  convint32_t(second.toString())));
  if (new_type == Float)
    return (createOperand(new_type, convinfloat(first.toString()) * 
			  convinfloat(second.toString())));
  if (new_type == Double)
    return (createOperand(new_type, convindouble(first.toString()) * 
			  convindouble(second.toString())));
  return (NULL);
}

template<typename T>
std::string		Operand<T>::convstr8(int8_t op)
{
  std::stringstream	oss;
  std::string		res;

  oss << op;
  oss >> res;
  return (res);
}

template<typename T>
std::string		Operand<T>::convstr16(int16_t op)
{
  std::stringstream	oss;
  std::string		res;

  oss << op;
  oss >> res;
  return (res);
}

template<typename T>
std::string		Operand<T>::convstr32(int32_t op)
{
  std::stringstream	oss;
  std::string		res;

  oss << op;
  oss >> res;
  return (res);
}

template<typename T>
std::string		Operand<T>::convstrfloat(float op)
{
  std::stringstream	oss;
  std::string		res;

  oss << op;
  oss >> res;
  return (res);
}

template<typename T>
std::string		Operand<T>::convstrdouble(double op)
{
  std::stringstream	oss;
  std::string		res;

  oss << op;
  oss >> res;
  return (res);
}

template<typename T>
int8_t		Operand<T>::convint8_t(std::string const op)
{
  std::stringstream	oss;
  int8_t		res;

  oss << op;
  oss >> res;
  return (res);
}

template<typename T>
int16_t		Operand<T>::convint16_t(std::string const op)
{
  std::stringstream	oss;
  int16_t		res;

  oss << op;
  oss >> res;
  return (res);
}

template<typename T>
int32_t		Operand<T>::convint32_t(std::string const op)
{
  std::stringstream	oss;
  int32_t		res;

  oss << op;
  oss >> res;
  return (res);
}

template<typename T>
float		Operand<T>::convinfloat(std::string const op)
{
  std::stringstream	oss;
  float			res;

  oss << op;
  oss >> res;
  return (res);
}

template<typename T>
double		Operand<T>::convindouble(std::string const op)
{
  std::stringstream	oss;
  double		res;

  oss << op;
  oss >> res;
  return (res);
}

template Operand<int8_t>::Operand(std::string op, eOperandType type);
template Operand<int16_t>::Operand(std::string op, eOperandType type);
template Operand<int32_t>::Operand(std::string op, eOperandType type);
template Operand<float>::Operand(std::string op, eOperandType type);
template Operand<double>::Operand(std::string op, eOperandType type);

template std::string const &Operand<int8_t>::toString() const;
template std::string const &Operand<int16_t>::toString() const;
template std::string const &Operand<int32_t>::toString() const;
template std::string const &Operand<float_t>::toString() const;
template std::string const &Operand<double>::toString() const;

template int	Operand<int8_t>::getPrecision() const;
template int	Operand<int16_t>::getPrecision() const;
template int	Operand<int32_t>::getPrecision() const;
template int	Operand<float>::getPrecision() const;
template int	Operand<double>::getPrecision() const;

template eOperandType	Operand<int8_t>::select_type(eOperandType first, eOperandType second);
template eOperandType	Operand<int16_t>::select_type(eOperandType first, eOperandType second);
template eOperandType	Operand<int32_t>::select_type(eOperandType first, eOperandType second);
template eOperandType	Operand<float>::select_type(eOperandType first, eOperandType second);
template eOperandType	Operand<double>::select_type(eOperandType first, eOperandType second);

template IOperand	*Operand<int8_t>::operator+(const IOperand &rhs) const;
template IOperand	*Operand<int16_t>::operator+(const IOperand &rhs) const;
template IOperand	*Operand<int32_t>::operator+(const IOperand &rhs) const;
template IOperand	*Operand<float>::operator+(const IOperand &rhs) const;
template IOperand	*Operand<double>::operator+(const IOperand &rhs) const;

template IOperand	*Operand<int8_t>::operator-(const IOperand &rhs) const;
template IOperand	*Operand<int16_t>::operator-(const IOperand &rhs) const;
template IOperand	*Operand<int32_t>::operator-(const IOperand &rhs) const;
template IOperand	*Operand<float>::operator-(const IOperand &rhs) const;
template IOperand	*Operand<double>::operator-(const IOperand &rhs) const;

template IOperand	*Operand<int8_t>::operator/(const IOperand &rhs) const;
template IOperand	*Operand<int16_t>::operator/(const IOperand &rhs) const;
template IOperand	*Operand<int32_t>::operator/(const IOperand &rhs) const;
template IOperand	*Operand<float>::operator/(const IOperand &rhs) const;
template IOperand	*Operand<double>::operator/(const IOperand &rhs) const;

template IOperand	*Operand<int8_t>::operator%(const IOperand &rhs) const;
template IOperand	*Operand<int16_t>::operator%(const IOperand &rhs) const;
template IOperand	*Operand<int32_t>::operator%(const IOperand &rhs) const;
template IOperand	*Operand<float>::operator%(const IOperand &rhs) const;
template IOperand	*Operand<double>::operator%(const IOperand &rhs) const;

template IOperand	*Operand<int8_t>::operator*(const IOperand &rhs) const;
template IOperand	*Operand<int16_t>::operator*(const IOperand &rhs) const;
template IOperand	*Operand<int32_t>::operator*(const IOperand &rhs) const;
template IOperand	*Operand<float>::operator*(const IOperand &rhs) const;
template IOperand	*Operand<double>::operator*(const IOperand &rhs) const;

template int8_t		Operand<int8_t>::convint8_t(std::string const op);
template int8_t		Operand<int16_t>::convint8_t(std::string const op);
template int8_t		Operand<int32_t>::convint8_t(std::string const op);
template int8_t		Operand<float>::convint8_t(std::string const op);
template int8_t		Operand<double>::convint8_t(std::string const op);

template int16_t	Operand<int8_t>::convint16_t(std::string const op);
template int16_t	Operand<int16_t>::convint16_t(std::string const op);
template int16_t	Operand<int32_t>::convint16_t(std::string const op);
template int16_t	Operand<float>::convint16_t(std::string const op);
template int16_t	Operand<double>::convint16_t(std::string const op);

template int32_t	Operand<int8_t>::convint32_t(std::string const op);
template int32_t	Operand<int16_t>::convint32_t(std::string const op);
template int32_t	Operand<int32_t>::convint32_t(std::string const op);
template int32_t	Operand<float>::convint32_t(std::string const op);
template int32_t	Operand<double>::convint32_t(std::string const op);

template float		Operand<int8_t>::convinfloat(std::string const op);
template float		Operand<int16_t>::convinfloat(std::string const op);
template float		Operand<int32_t>::convinfloat(std::string const op);
template float		Operand<float>::convinfloat(std::string const op);
template float		Operand<double>::convinfloat(std::string const op);

template double		Operand<int8_t>::convindouble(std::string const op);
template double		Operand<int16_t>::convindouble(std::string const op);
template double		Operand<int32_t>::convindouble(std::string const op);
template double		Operand<float>::convindouble(std::string const op);
template double		Operand<double>::convindouble(std::string const op);
