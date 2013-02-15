//
// Tasks.hpp for abstractvm in /home/audrade/work/abstractvm-2014-caille_c
// 
// Made by cailleux carole
// Login   <caille_c@epitech.net>
// 
// Started on  Fri Feb 18 11:45:18 2011 cailleux carole
// Last update Sat Feb 19 11:11:29 2011 raphael chambily
//

#ifndef			__TASKS_HPP__
# define		__TASKS_HPP__

#include <string>
#include <queue>

class			Tasks
{
public:
  Tasks();
  ~Tasks();

  void		add(std::string str);
  void		execute();
  
private:
  std::queue<std::string>	_tasks;
};

#endif
