/*
** mallocat.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 11:03:10 2017 benoit pingris
** Last update Wed Jun 21 19:43:49 2017 benoit pingris
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"

char	*mallocat(char *s1, char *s2)
{
  int	i;
  char	*new;

  if (!s1)
    i = strlen(s2);
  else
    i = strlen(s1) + strlen(s2);
  if (!(new = malloc(sizeof(char) * (i + 3))))
    return (NULL);
  if (s1)
    {
      if (s1[strlen(s1) - 1] != '/')
	sprintf(new, "%s/%s", s1, s2);
      else
	sprintf(new, "%s%s", s1, s2);
    }
  else
    sprintf(new, "%s", s2);
  return (new);
}

char	*add_brackets(char *s)
{
  char	*cpy;

  if (!(cpy = malloc(sizeof(char) * (strlen(s) + 4))))
    return (NULL);
  sprintf(cpy, "[%s]", s);
  free(s);
  return (cpy);
}

int	brackets(char *s)
{
  if (s[0] != '[' && s[strlen(s) - 1] != ']')
    return (SUCCESS);
  return (ERROR);
}
