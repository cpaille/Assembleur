/*
** xmalloc.c for libmy.a
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Tue Mar 13 10:11:50 2012 matthieu przybylski
** Last update Fri Mar 23 17:26:25 2012 matthieu przybylski
*/

#include <stdlib.h>
#include "my.h"

void    *xmalloc(int size)
{
  void  *ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    xexit("Error : can't perform malloc\n");
  return (ptr);
}
