/*
** slash.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 18:11:13 2017 benoit pingris
** Last update Wed Jun 21 18:12:35 2017 benoit pingris
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "macro.h"

char	*slash(char *s)
{
  char	*cpy;

  if (!(cpy = malloc(sizeof(char) * (strlen(s) + 3))))
    return (NULL);
  if (sprintf(cpy, "%s/", s) == -FAILURE)
    return (NULL);
  free(s);
  return (cpy);
}

char	**add_slash(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      if (tab[i][strlen(tab[i]) - 1] != '/')
	if (!(tab[i] = slash(tab[i])))
	  return (NULL);
      ++i;
    }
  return (tab);
}
