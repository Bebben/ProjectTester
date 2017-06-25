/*
** set.c for projetexst in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 16:47:37 2017 benoit pingris
** Last update Sat Jun 24 15:54:17 2017 benoit pingris
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "macro.h"

int	set_struct(t_exec *exec, char *s, char *root)
{
  exec->root = root;
  exec->res = NULL;
  if (s)
    {
      if (!(exec->exec = strdup(s)) ||
	  !(exec->exec_path = strdup(s)))
	return (ERROR);
    }
  else
    exec->exec = NULL;
  exec->find = 0;
  if (!(exec->origin = getcwd(NULL, 0)))
    return (ERROR);
  return (SUCCESS);
}
