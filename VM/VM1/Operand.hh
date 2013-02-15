/*
** OperandInt8.h for OperandInt8.h in /home/bigup/prog/svn-projet-pitek/C++/vm_abstract/
** 
** Made by dimitri doyen
** Login   <doyen_d@epitech.net>
** 
** Started on  Thu Feb 17 11:59:04 2011 dimitri doyen
// Last update Sun Feb 20 23:27:42 2011 anthony reboul
*/

#ifndef   	__OPERAND_H__
# define   	__OPERAND_H__

#include "Cpu.hh"
#include "IOperand.hh"

template<typename T>
class		Operand : public IOperand, Cpu
{
 protected:
  std::string	_soperand;
  T		_toperand;
  eOperandType	_type;

  eOperandType	select_type(eOperandType, eOperandType) const;
  int8_t	convint8_t(std::string const);
  int16_t	convint16_t(std::string const);
  int32_t	convint32_t(std::string const);
  float		convinfloat(std::string const);
  double	convindouble(std::string const);

 public:
  virtual std::string const & toString() const;
  virtual int getPrecision() const;
  virtual eOperandType getType() const;

  virtual IOperand *operator+(const IOperand &rhs) const;
  virtual IOperand *operator-(const IOperand &rhs) const;
  virtual IOperand *operator*(const IOperand &rhs) const;
  virtual IOperand *operator/(const IOperand &rhs) const;
  virtual IOperand *operator%(const IOperand &rhs) const;
  Operand(std::string, eOperandType);
  virtual ~Operand() {}
};


#endif 	    /* !__OPERAND_H__ */
