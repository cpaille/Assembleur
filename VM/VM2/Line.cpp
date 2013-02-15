//
// line.cpp for abstractvm in /home/audrade/work/abstractvm-2014-caille_c
// 
// Made by cailleux carole
// Login   <caille_c@epitech.net>
// 
// Started on  Thu Feb 17 11:05:14 2011 cailleux carole
// Last update Sat Feb 19 14:55:52 2011 raphael chambily
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Line.hpp"
#include "VmStack.hpp"

Line::Line(std::string const& line)
  : _content(line)
{
}

Line::~Line()
{
}

void			Line::clean()
{
  std::string		str;
  std::string		res("");
  std::istringstream	iss;

  iss.str(this->_content);
  while (iss >> str >> std::ws)
    {
      if (res != "")
	res += " ";
      // else
      // 	{
      // 	  if (str[0] == ';' && ((str[1] && str[1] != ';') || !str[1]))
      // 	    return ;
      // 	}
      res += str;
    }
  iss.clear();
  if (!res.empty())
    this->setContent(res);
}

std::string	Line::getContent()
{
  return (this->_content);
}

void		Line::setContent(std::string const& content)
{
  this->_content = content;
}
