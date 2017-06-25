/*
** main.c for projtester in /home/benoit.pingris/delivery/github_perso/projTest
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 20 20:39:16 2017 benoit pingris
** Last update Fri Jun 23 14:51:16 2017 benoit pingris
*/

#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "useful.h"
#include "macro.h"
#include "proj.h"

int		is_dir(char *name)
{
  DIR		*dir;

  if (!name)
    return (ERROR);
  if (!(dir = opendir(name)))
    return (ERROR);
  if (closedir(dir) == -FAILURE)
    return (ERROR);
  return (SUCCESS);
}

int		my_output(char *s)
{
  int		fd;

  if ((fd = open(s, O_RDWR | O_CREAT | O_APPEND, 0777)) == -FAILURE)
    return (ERROR);
  dup2(fd, STDOUT_FILENO);
  dup2(fd, STDERR_FILENO);
  return (SUCCESS);
}

int		main(int ac, char **av, char **envp)
{
  t_exec	exec;
  int		check;

  if (ac == 1)
    return (putstr(USG, ERROR, STDERR_FILENO));
  if (is_dir(av[1]) == ERROR)
    return (ERROR);
  set_struct(&exec, av[2], av[1]);
  if (ac == 2)
    my_tree(av[1], NULL, &exec);
  else if (ac > 2 && ac <= 4)
    {
      if (av[3] && my_output(av[3]) == ERROR)
	return (ERROR);
      if (exec.exec && (check = find_in_path(exec.exec, envp)) == SUCCESS)
	exec.find = 1;
      if (exec.find == 0 || check == ERROR)
	my_tree("./", NULL, &exec);
      if (exec.find == 0 && ac == 3)
	return (putstr(NO_BINARY, ERROR, STDERR_FILENO));
      if (recu_tree(av[1], "./", &exec) == ERROR)
	return (ERROR);
    }
  free(exec.exec);
  return (SUCCESS);
}
