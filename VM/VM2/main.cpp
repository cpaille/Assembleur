//
// main.cpp for abstract_vm in /home/chambi_r//proj/abstract_vm
// 
// Made by raphael chambily
// Login   <chambi_r@epitech.net>
// 
// Started on  Mon Feb 14 18:05:40 2011 raphael chambily
// Last update Sat Feb 19 19:09:45 2011 raphael chambily
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "VmStack.hpp"
#include "exception.hpp"
#include "Line.hpp"
#include "Tasks.hpp"


int		main(int ac, char **av)
{
  std::string		in;
  Line			*myLine;
  Tasks			tasks;

  try
    {
      if (ac > 1)
	{
	  std::ifstream file(av[1], std::ios::in);

	  if (!file)
	    { throw myException("File not found"); }
	  do
	    {
	      getline(file, in);
	      myLine = new Line(in);
	      myLine->clean();
	      tasks.add(myLine->getContent());
	      delete myLine;
	    } while (in != "exit" && in != ";;");
	  file.close();
	}
      else
	do 
	  {
	    getline(std::cin, in, '\n');
	    myLine = new Line(in);
	    myLine->clean();
	    tasks.add(myLine->getContent());
	    delete myLine;
	  } while (in.find(";;") == in.npos);
      tasks.execute();
    }
  catch(const myException& e)
    { std::cerr << "ERROR : " << e.what() << std::endl; }
  return 0;
}
