//
// Chipset.hh for chipset in /home/reboul_a//work/tek2/svn-projet-pitek/C++/vm_abstract
// 
// Made by anthony reboul
// Login   <reboul_a@epitech.net>
// 
// Started on  Mon Feb 14 15:01:00 2011 anthony reboul
// Last update Sun Feb 20 22:29:06 2011 anthony reboul
//

#ifndef	__CHIPSET_H__
# define __CHIPSET_H__

#include "Cpu.hh"
#include <iostream>
#include <fstream>
#include <string>

class		Chipset
{
protected:
  Cpu		*my;
  int		parse_line(std::string, int);
  int		verif_error(e_err, int);
  int		add_arg(std::string, std::string, int);

public:
  void		execute_file(char *);
  void		execute_entry();
  Chipset();
  ~Chipset();
};

#endif
