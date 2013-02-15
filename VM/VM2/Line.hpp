//
// line.hpp for abstractvm in /home/audrade/work/abstractvm-2014-caille_c
// 
// Made by cailleux carole
// Login   <caille_c@epitech.net>
// 
// Started on  Thu Feb 17 10:59:24 2011 cailleux carole
// Last update Thu Feb 17 10:59:24 2011 cailleux carole
//

#ifndef			__LINE_HPP__
# define		__LINE_HPP__

#include <string>

class Line
{
public:
  Line(std::string const& line);
  ~Line();

  void		clean();

  std::string	getContent();
  void		setContent(std::string const& content);

private:
  std::string		_content;
};

#endif
