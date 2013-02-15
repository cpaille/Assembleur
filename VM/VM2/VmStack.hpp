//
// VmStack.hpp for Abstract Vm in /home/chambi_r//.ssh/abstractvm-2014-caille_c
// 
// Made by raphael chambily
// Login   <chambi_r@epitech.net>
// 
// Started on  Tue Feb 15 11:59:33 2011 raphael chambily
// Last update Sat Feb 19 12:23:42 2011 raphael chambily
//

#ifndef __VMSTACK_HPP__
# define __VMSTACK_HPP__

#include <iostream>
#include <deque>
#include <map>
#include <string>
#include "Operand.hpp"

class	VmStack
{
private:
  std::deque<IOperand *>			_values;
  std::map<std::string, void (VmStack::*)()>	funcs;
  std::map<std::string, IOperand* (VmStack::*)(std::string const&)>	funcs_types;

public:
  VmStack();
  ~VmStack();
  void		func_call(std::string s1, std::string s2 = "");

  IOperand	*get_operand(std::string const& str);

private:
  void		push(IOperand *arg);
  void		pop();
  void		dump();
  void		assert(IOperand *arg);
  void		add();
  void		sub();
  void		mul();
  void		div();
  void		mod();
  void		print();

  IOperand	*create_int8(std::string const& value);
  IOperand	*create_int16(std::string const& value);
  IOperand	*create_int32(std::string const& value);
  IOperand	*create_float(std::string const& value);
  IOperand	*create_double(std::string const& value);
};

#endif
