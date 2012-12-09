/*
** xrealloc.c for libmy.a
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Tue Mar 13 10:08:14 2012 matthieu przybylski
** Last update Tue Mar 13 10:10:29 2012 matthieu przybylski
*/

#include <stdlib.h>
#include "my.h"

void    *xrealloc(void *ptr, int size)
{
  ptr = realloc(ptr, size);
  if (ptr == NULL)
    xexit("Error : could not realloc.\n");
  return (ptr);
}
