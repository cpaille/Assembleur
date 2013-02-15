//
// IOperand.hh
// 
// Made by dimitri doyen
// Login   <doyen_d@epitech.net>
// 
// Started on  Mon Feb 14 13:24:22 2011 dimitri doyen
// Last update Sun Feb 20 20:51:41 2011 dimitri doyen
//

#ifndef   	IOPERAND_HH_
# define   	IOPERAND_HH_

#include <iostream>
#include <stdint.h>

typedef enum e_opetype
  {
    Int8,
    Int16,
    Int32,
    Float,
    Double,
    End
  }
  eOperandType;

class IOperand
{
public:
  virtual std::string const & toString() const = 0; // renvoie une string representant l'instance
  virtual int getPrecision() const = 0; // renvoie la precision du type de l'instance
  virtual eOperandType getType() const = 0; // Renvoie le type de l'instance

  virtual IOperand * operator+(const IOperand &rhs) const = 0; // somme
  virtual IOperand * operator-(const IOperand &rhs) const = 0; // diff
  virtual IOperand * operator*(const IOperand &rhs) const = 0; // produit
  virtual IOperand * operator/(const IOperand &rhs) const = 0; // quotient
  virtual IOperand * operator%(const IOperand &rhs) const = 0; // modulo

  virtual ~IOperand() {}
};

#endif	    /* !IOPERAND_HH_ */
