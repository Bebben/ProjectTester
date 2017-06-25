/*
** parser.c for projecttester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 21:31:22 2017 benoit pingris
** Last update Thu Jun 22 19:55:25 2017 benoit pingris
*/

#include <unistd.h>
#include <string.h>
#include "macro.h"
#include "struct.h"
#include "useful.h"

int	print_path(char *s)
{
  int	i;

  i = 0;
  my_putchar('[');
  while (s[i])
    {
      if (s[i] == '/')
	{
	  putstr("] [", SUCCESS, STDOUT_FILENO);
	  ++i;
	}
      my_putchar(s[i]);
      ++i;
    }
  putstr("] ", SUCCESS, STDOUT_FILENO);
  return (SUCCESS);
}

int	my_parser(t_exec *exec, char *path)
{
  char	*tmp;

  tmp = strstr(path, exec->root);
  tmp = &tmp[strlen(exec->root)];
  if (tmp[0] == '/')
    ++tmp;
  if (strlen(tmp) > 0)
    print_path(tmp);
  return (SUCCESS);
}
