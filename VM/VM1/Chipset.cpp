//
// Chipset.cpp for chipset.cpp in /home/reboul_a//work/tek2/svn-projet-pitek/C++/vm_abstract
// 
// Made by anthony reboul
// Login   <reboul_a@epitech.net>
// 
// Started on  Mon Feb 14 15:15:03 2011 anthony reboul
// Last update Sun Feb 20 22:27:11 2011 anthony reboul
//

#include "Chipset.hh"

int		Chipset::verif_error(e_err type, int no_line)
{
  if (type == NONE)
    return (0);
  else if (type == POP)
    std::cout << "Error line " << no_line << " on pop : stack is empty" << std::endl;
  else if (type == ASSERT)
    std::cout << "Error line " << no_line << " on assert : incorrect value" << std::endl;
  else if (type == PUSH)
    std::cout << "Error line " << no_line << " on push : incorrect value" << std::endl;
  else if (type == ADD)
    std::cout << "Error line " << no_line << " on add : there is less than 2 value on stack" << std::endl;
  else if (type == SUB)
    std::cout << "Error line " << no_line << " on sub : there is less than 2 value on stack" << std::endl;
  else if (type == MUL)
    std::cout << "Error line " << no_line << " on mul : there is less than 2 value on stack" << std::endl;
  else if (type == DIV)
    std::cout << "Error line " << no_line << " on div : there is less than 2 value on stack" << std::endl;
  else if (type == MOD)
    std::cout << "Error line " << no_line << " on mod : there is less than 2 value on stack" << std::endl;
  else if (type == PRINT)
    std::cout << "Error line " << no_line << " on print : incorrect value" << std::endl;
  return (-1);
}


int		Chipset::add_arg(std::string command, std::string line, int no_line)
{
  size_t	pos;
  std::string	arg;

  pos = line.find(command) + command.size() + 1;
  while (line[pos] != ' ' && line[pos] != '\0')
    {
      arg = arg + line[pos];
      pos++;
    }    
  return (verif_error(my->execute_line(command, arg), no_line));
}

int		Chipset::parse_line(std::string line, int no_line)
{
  size_t	found = -1;
  std::string	command;
  std::string	arg;

  found = line.find(";");
  if (line.find(";;") != std::string::npos || line.find("exit") != std::string::npos)
    return (-1);
  else if (line.find("pop") != std::string::npos && line.find("pop") < found)
    return (verif_error(my->execute_line("pop", ""), no_line));
  else if (line.find("add") != std::string::npos && line.find("add") < found)
    return (verif_error(my->execute_line("add", ""), no_line));
  else if (line.find("sub") != std::string::npos && line.find("sub") < found)
    return (verif_error(my->execute_line("sub", ""), no_line));
  else if (line.find("mul") != std::string::npos && line.find("mul") < found)
    return (verif_error(my->execute_line("mul", ""), no_line));
  else if (line.find("div") != std::string::npos && line.find("div") < found)
    return (verif_error(my->execute_line("div", ""), no_line));
  else if (line.find("mod") != std::string::npos && line.find("mod") < found)
    return (verif_error(my->execute_line("mod", ""), no_line));
  else if (line.find("dump") != std::string::npos && line.find("dump") < found)
    return (verif_error(my->execute_line("dump", ""), no_line));
  else if (line.find("push") != std::string::npos && line.find("push") < found)
    return (add_arg("push", line, no_line));
  else if (line.find("print") != std::string::npos && line.find("print") < found)
    return (verif_error(my->execute_line("print", ""), no_line));
  else if (line.find("assert") != std::string::npos && line.find("assert") < found)
    return (add_arg("assert", line, no_line));
  else if (found == std::string::npos)
    {
      std::cout << "Error line " << no_line << " : unknown command" << std::endl;
      return (-1);
    }
  else
    std::cout << "ligne commentee" << std::endl;
  return (0);
}

void		Chipset::execute_entry()
{
  std::string	line;
  std::string	temp;
  int		no_line = 0;

  while (1)
    {
      std::cin >> line;
      if (line.find("assert") != std::string::npos || line.find("push") != std::string::npos)
	{
	  std::cin >> temp;
	  line.insert(line.size(), " " + temp);
	}
      if (parse_line(line, no_line) == -1)
	return ;
      no_line++;
    }
}

void		Chipset::execute_file(char *file)
{
  std::fstream	filestr;
  std::string	s;
  int		no_line = 0;

  filestr.open(file, std::fstream::in);
  if (filestr.fail() == true)
    {
      std::cout << "Error no such file or directory" << std::endl;
      return ;
    }
  while (getline(filestr, s))
    {
      if (parse_line(s, no_line) == -1)
	return ;
      no_line++;
    }
}

Chipset::Chipset()
{
  my = new Cpu;
}

Chipset::~Chipset()
{
}
