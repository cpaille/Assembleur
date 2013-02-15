//
// main.cpp for main in /home/reboul_a//work/tek2/svn-projet-pitek/C++/vm_abstract
// 
// Made by anthony reboul
// Login   <reboul_a@epitech.net>
// 
// Started on  Mon Feb 14 15:01:18 2011 anthony reboul
// Last update Thu Feb 17 15:25:36 2011 anthony reboul
//

#include "Chipset.hh"

int		main(int argc, char **argv)
{
  Chipset	*chip;

  if (argc > 2)
    {
      std::cout << "Error: Incorect number of arguments" << std::endl;
      return (0);
    }
  chip = new Chipset;
  if (argc == 1)
    chip->execute_entry();
  else
    chip->execute_file(argv[1]);
  return (0);
}
