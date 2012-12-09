/*
** xexit.c for libmy.a
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Tue Mar 13 10:12:42 2012 matthieu przybylski
** Last update Tue Mar 13 10:12:48 2012 matthieu przybylski
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void    xexit(char *error)
{
  write(2, error, my_strlen(error));
  exit(EXIT_FAILURE);
}
