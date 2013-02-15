//
// exception.cpp for abstract_vm in /home/audrade/work/abstractvm-2014-caille_c
// 
// Made by cailleux carole
// Login   <caille_c@epitech.net>
// 
// Started on  Tue Feb 15 17:21:50 2011 cailleux carole
// Last update Tue Feb 15 17:21:50 2011 cailleux carole
//

#include <exception>
#include "exception.hpp"

myException::myException(std::string const& msg) throw()
  :  _msg(msg)
{
}

myException::~myException() throw()
{
}

const char*		myException::what() const throw()
{
  return (this->_msg.c_str());
}
