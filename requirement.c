/*
** requirement.c for projtest in /home/benoit.pingris/delivery/github_perso/projTest
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 20 20:32:03 2017 benoit pingris
** Last update Wed Jun 21 11:09:24 2017 benoit pingris
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void	my_ps_synthesis()
{
  pid_t	p;

  ((p = fork()) == -1 ? exit(0) :
   (p == 0 ? execlp("ps", "ps", NULL) : wait(NULL)));
}
