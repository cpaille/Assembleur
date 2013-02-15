//
// exception.hpp for abstract_vm in /home/audrade/work/abstractvm-2014-caille_c
// 
// Made by cailleux carole
// Login   <caille_c@epitech.net>
// 
// Started on  Tue Feb 15 16:38:35 2011 cailleux carole
// Last update Tue Feb 15 16:38:35 2011 cailleux carole
//

#ifndef		__MY_EXCEPTION_HPP__
# define	__MY_EXCEPTION_HPP__

#include <string>
#include <exception>

class myException : public std::exception
{
public:
  myException(std::string const& msg) throw();
  virtual ~myException() throw();

  virtual const char* what() const throw();

private:
  std::string	_msg;
};

#endif
