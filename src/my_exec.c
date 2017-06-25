/*
** my_exec.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Jun 22 11:40:48 2017 benoit pingris
** Last update Sat Jun 24 17:04:36 2017 benoit pingris
*/

#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "macro.h"
#include "useful.h"
#include "proj.h"
#include "gnl.h"

void	dup_exec(int fd, char **tab, t_exec *exec, int *fd_p)
{
  close(fd_p[0]);
  if (fd != DEF_FD)
    dup2(fd, STDIN_FILENO);
  dup2(fd_p[1], STDOUT_FILENO);
  dup2(fd_p[1], STDERR_FILENO);
  execvp(exec->exec_path, tab);
  exit(0);
}

void	disp_res(char *res, int *fd_p)
{
  char	*s;
  int	check;

  check = 0;
  close(fd_p[1]);
  if (res)
    {
      while ((s = get_next_line(fd_p[0])))
      {
	if (strcmp(s, res) != SAME)
	  check = 1;
	free(s);
      }
      putstr(check == 0 ? "OK\n" : "KO\n", SUCCESS, STDOUT_FILENO);
    }
  else
    while ((s = get_next_line(fd_p[0])))
      {
	putstr(s, SUCCESS, STDOUT_FILENO);
	my_putchar('\n');
	free(s);
      }
}

int	my_exec(char **tab, int fd, t_exec *exec)
{
  pid_t	pid;
  int	fd_p[2];

  pipe(fd_p);
  if ((pid = fork()) == -FAILURE)
    return (ERROR);
  if (pid == 0)
    dup_exec(fd, tab, exec, fd_p);
  else
    wait(NULL);
  disp_res(exec->res, fd_p);
  return (SUCCESS);
}
