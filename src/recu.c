/*
** recu.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 18:29:01 2017 benoit pingris
** Last update Sat Jun 24 15:53:27 2017 benoit pingris
*/

#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "useful.h"
#include "macro.h"
#include "proj.h"
#include "gnl.h"

void	print_file(char *s)
{
  disp_file(s);
  putstr(": ", SUCCESS, STDOUT_FILENO);
}

void	exec_cmd(t_exec *exec, char **tab, int fd2, int fd)
{
  chdir(exec->origin);
  my_exec(tab, fd2, exec);
  if (fd2 != DEF_FD)
    close(fd2);
  free_tab(tab);
  close(fd);
}

int	take_res(t_exec *exec, char *s)
{
  s = strstr(s, ":");
  ++s;
  if (s[0] == ' ')
    ++s;
  if (!(exec->res = strdup(s)))
    return (ERROR);
  return (SUCCESS);
}

int	cat_args(char *path, char *file, t_exec *exec, int fd2)
{
  char	**tab;
  char	*tmp;
  char	*s;
  int	fd;

  if ((!(tmp = mallocat(path, file)) || !(tab = set_tab(exec->exec)) ||
       (fd = open(tmp, O_RDONLY)) == -FAILURE))
    return (ERROR);
  print_file(file);
  while ((s = get_next_line(fd)))
    {
      if (!(s = epur_str(s)))
	return (ERROR);
      if (strncmp(s, "ARGS:", 5) == SAME && (int)strlen(s) > 5)
	tab = get_info(s, exec->exec);
      if (strncmp(s, "INPUT:", 6) == 0 && change_stream(path, s, &fd2) == 84)
	return (ERROR);
      if (strncmp(s, "RES:", 4) == SAME && take_res(exec, s) == ERROR)
	return (ERROR);
      free(s);
    }
  exec_cmd(exec, tab, fd2, fd);
  free(tmp);
  return (SUCCESS);
}

int	recu_tree(char *name, char *parent, t_exec *exec)
{
  char		**tab;
  char		*path;
  static char	*tmp;
  int		i;

  i = 0;
  if (!(path = mallocat(parent, name)) || !(tab = get_tab(path)))
    return (ERROR);
  tmp = NULL;
  tmp = mallocat(tmp, name);
  while (tab[i])
    {
      if (is_file(mallocat(path, tab[i])) == 1)
	recu_tree(tab[i], path, exec);
      else if (strstr(tab[i], ".tdf"))
	{
	  my_parser(exec, path);
	  if (cat_args(path, tab[i], exec, DEF_FD) == ERROR)
	    return (ERROR);
	}
      ++i;
    }
  free_things(path, tab);
  return (SUCCESS);
}
