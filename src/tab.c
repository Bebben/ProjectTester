/*
** tab.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 18:13:49 2017 benoit pingris
** Last update Sat Jun 24 15:54:53 2017 benoit pingris
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "useful.h"
#include "macro.h"
#include "proj.h"

char	**get_tab(char *path)
{
  char	**tab;

  if (!(tab = get_files(path)))
    return (NULL);
  sort_tab(tab);
  return (tab);
}

int	is_file_ok(char *path, char *s)
{
  char	*tmp;

  if (!(tmp = malloc(sizeof(char) * (strlen(s) + strlen(path) + 2))))
    return (ERROR);
  if (path[strlen(path) - 1] != '/')
    sprintf(tmp, "%s/%s", path, s);
  else
    sprintf(tmp, "%s%s", path, s);
  if (access(tmp, X_OK) == 0)
    return (SUCCESS);
  return (FAILURE);
}

int	print_find(char *s, int dash, t_exec *exec, char *path)
{
  if (!exec->exec)
    print_dash(dash, s, FALSE);
  else if (strcmp(exec->exec, s) == SAME &&
	   is_file_ok(path, s) == 0)
    {
      exec->find = 1;
      exec->exec_path = mallocat(path, exec->exec);
    }
  return (SUCCESS);
}
