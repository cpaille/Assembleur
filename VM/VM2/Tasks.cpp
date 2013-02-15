//
// Tasks.cpp for abstractvm in /home/audrade/work/abstractvm-2014-caille_c
// 
// Made by cailleux carole
// Login   <caille_c@epitech.net>
// 
// Started on  Fri Feb 18 11:47:33 2011 cailleux carole
// Last update Sat Feb 19 19:11:56 2011 raphael chambily
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Tasks.hpp"
#include "VmStack.hpp"

Tasks::Tasks()
{
}


Tasks::~Tasks()
{
}

void		Tasks::add(std::string str)
{
  if (!str.empty() && str[0] != ';')
    this->_tasks.push(str);
}

void		Tasks::execute()
{
  VmStack	avm;
  std::string	str;
  std::string	instruction;
  std::string	arg;
  std::istringstream	iss;

  try {
    while (!(this->_tasks.empty()))
      {
	iss.str(this->_tasks.front());
	iss >> instruction >> std::ws;
	if (instruction == "exit")
	  break;
	if (iss >> arg >> std::ws)
	  avm.func_call(instruction, arg);
	else
	  avm.func_call(instruction);
	iss.clear();
	this->_tasks.pop();
      }
    if (instruction != "exit")
      throw myException("Instructions must be ended by the 'exit' statement");
  }
  catch(const myException& e)
    { std::cerr << "ERROR : " << e.what() << std::endl; }
}
