/*
** putstr.c for projtester in /home/benoit.pingris/delivery/github_perso/projTest
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 20 20:43:37 2017 benoit pingris
** Last update Tue Jun 20 22:57:56 2017 benoit pingris
*/

#include <unistd.h>
#include <string.h>
#include "macro.h"

int	putstr(char *s, int ret, int stream)
{
  write(stream, s, strlen(s));
  return (ret);
}

void	my_putchar(char a)
{
  write(1, &a, 1);
}

void	showtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      putstr(tab[i], SUCCESS, STDOUT_FILENO);
      my_putchar('\n');
      ++i;
    }
}
