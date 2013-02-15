//
// Cpu.hh for cpu in /home/reboul_a//work/tek2/svn-projet-pitek/C++/vm_abstract
// 
// Made by anthony reboul
// Login   <reboul_a@epitech.net>
// 
// Started on  Tue Feb 15 12:02:50 2011 anthony reboul
// Last update Sun Feb 20 23:14:50 2011 anthony reboul
//

#ifndef __CPU_H__
# define __CPU_H__

#include <iostream>
#include <list>
#include "IOperand.hh"

typedef enum	e_err
  {
    POP,
    ASSERT,
    PUSH,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    PRINT,
    NONE
  } e_err;

class		Cpu
{
  std::list<IOperand *>	my_list;

  std::string	found_value(size_t, std::string);
  std::string	listtostring(std::list<IOperand *>::iterator const);

  e_err		pop();
  void		dump();
  e_err		assert(std::string);
  e_err		push(std::string);
  e_err		add();
  e_err		sub();
  e_err		mul();
  e_err		div();
  e_err		mod();
  e_err		print();

  IOperand	*createInt8(const std::string &value);
  IOperand	*createInt16(const std::string &value);
  IOperand	*createInt32(const std::string &value);
  IOperand	*createFloat(const std::string &value);
  IOperand	*createDouble(const std::string &value);

public:
  Cpu();
  ~Cpu();
  e_err		execute_line(std::string, std::string);
  IOperand	*createOperand(eOperandType type, const std::string &value);
};

#endif
