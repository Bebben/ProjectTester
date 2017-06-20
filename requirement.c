/*
** requirement.c for projtest in /home/benoit.pingris/delivery/github_perso/projTest
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 20 20:32:03 2017 benoit pingris
** Last update Tue Jun 20 20:36:01 2017 benoit pingris
*/

#include <sys/wait.h>
#include <unistd.h>

void	my_ps_synthesis()
{
  pid_t	pid;
  int	status;

  if ((pid = fork()) == -1)
    return;
  if (pid == 0)
    execlp("ps", "ps", NULL);
  else
    wait(&status);
}
