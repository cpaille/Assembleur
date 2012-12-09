/*
** get_next_line.c for get_next_line in /home/dediss_q//tmp/get_next_line/rendu/getnextline/final
**
** Made by quentin dedisse
** Login   <dediss_q@epitech.net>
**
** Started on  Wed Nov 28 00:47:15 2012 quentin dedisse
** Last update Wed Nov 28 01:30:29 2012 quentin dedisse
*/

#include "get_next_line.h"
#include <stdlib.h>

int	put_save_in_ret(char *ret[1], char *save, char *tmp, int ret_len)
{
  int	i;
  int	save_len;

  save_len = 0;
  while (save[save_len] != '\0' && save[save_len] != '\n')
    save_len++;
  ret[0] = malloc(sizeof(**ret) * (ret_len + save_len + 1));
  if (ret[0] == NULL)
    return (-1);
  i = 0;
  while (i < ret_len)
    {
      ret[0][i] = tmp[i];
      i++;
    }
  i = 0;
  while (i < save_len)
    {
      ret[0][i + ret_len] = save[i];
      i++;
    }
  free(tmp);
  ret[0][i + ret_len] = '\0';
  return ((save[i] == '\n'));
}

int	add_save_to_ret(char *ret[1], char *save)
{
  char	*tmp;
  int	ret_len;
  int	i;

  if (save[0] == '\0')
    return (0);
  ret_len = 0;
  while (ret[0][ret_len])
    ret_len++;
  tmp = malloc(sizeof(*tmp) * (ret_len + 1));
  if (tmp == NULL)
    return (-1);
  i = 0;
  while (i <= ret_len)
    {
      tmp[i] = ret[0][i];
      i++;
    }
  free(*ret);
  return (put_save_in_ret(ret, save, tmp, ret_len));
}

void	evolve_save(char *buff)
{
  int	i;

  while (buff[0] != '\0' && buff[0] != '\n')
    {
      i = 0;
      while (buff[i] != '\0')
	{
	  buff[i] = buff[i + 1];
	  i++;
	}
    }
  i = 0;
  while (buff[i] != '\0')
    {
      buff[i] = buff[i + 1];
      i++;
    }
}

int		test_last_line(char buff[NBREAD + 1])
{
  static int	last_line = 0;

  if (buff[0] == '\0' && last_line == 0)
    {
      last_line = 1;
      return (1);
    }
  if (buff[0] == '\0' && last_line == 1)
    return (-1);
  return (0);
}

char		*get_next_line(const int fd)
{
  static	char buff[NBREAD + 1];
  char		*ret[1];
  int		val_ret;
  int		rd;

  if (NBREAD <= 0)
    return (0);
  ret[0] = malloc(sizeof(**ret));
  if (ret[0] == NULL)
    return (0);
  ret[0][0] = '\0';
  while ((val_ret = add_save_to_ret(ret, buff)) != 1)
    {
      if (val_ret == -1)
      	return (0);
      rd = read(fd, buff, NBREAD);
      buff[rd] = '\0';
      if (test_last_line(buff) == 1)
	return (ret[0]);
      else if (test_last_line(buff) == -1)
	{
	  free(ret[0]);
	  return (0);
	}
    }
  evolve_save(buff);
  return (ret[0]);
}
