//
// IOperand.hpp for Abstract VM in /home/chambi_r//.ssh/abstractvm-2014-caille_c
// 
// Made by raphael chambily
// Login   <chambi_r@epitech.net>
// 
// Started on  Tue Feb 15 13:58:43 2011 raphael chambily
// Last update Tue Feb 15 13:59:14 2011 raphael chambily
//

#ifndef		__IOPERAND_HPP__
# define	__IOPERAND_HPP__

enum			eOperandType
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
  };

class			IOperand
{
public:
  virtual std::string const& toString() const = 0;

  virtual int getPrecision() const = 0;
  virtual eOperandType getType() const = 0;

  virtual IOperand *operator+(const IOperand &rhs) const = 0;
  virtual IOperand *operator-(const IOperand &rhs) const = 0;
  virtual IOperand *operator*(const IOperand &rhs) const = 0;
  virtual IOperand *operator/(const IOperand &rhs) const = 0;
  virtual IOperand *operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {}
};

#endif
