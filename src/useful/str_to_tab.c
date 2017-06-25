/*
** str_to_tab.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Jun 22 10:54:38 2017 benoit pingris
** Last update Thu Jun 22 18:50:53 2017 benoit pingris
*/

#include <stdlib.h>
#include <string.h>
#include "useful.h"

char	**my_malloc(char *s)
{
  char **tab;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * (strlen(s) + 1))) == NULL)
    return (NULL);
  while (i < (int)strlen(s))
    {
      if ((tab[i] = malloc(sizeof(char) * (strlen(s) + 1))) == NULL)
	return (NULL);
      ++i;
    }
  return (tab);
}

char	**str_to_tab(char *s, char **tab)
{
  int	i;
  int	j;
  int	k;

  if ((i = 0) == 0 && (j = 0) == 0 && (tab = my_malloc(s)) == NULL)
    return (NULL);
  while (s[i])
    {
      k = 0;
      while (s[i] && s[i] == ' ')
	++i;
      while (s[i] && s[i] != ' ')
	tab[j][k++] = s[i++];
      tab[j++][k] = '\0';
    }
  if (strlen(tab[--j]) == 0)
    tab[j] = NULL;
  else
    tab[++j] = NULL;
  return (tab);
}

char	**add_in_array(char **tab, char *s)
{
  char	**cpy;
  int	i;
  int	j;

  if ((i = 0) == 0 && (j = 0) == 0 &&
      !(cpy = malloc(sizeof(char *) * (tab_len(tab) + 3))))
    return (NULL);
  if (!(cpy[i++] = strdup(s)))
    return (NULL);
  while (tab[j])
    {
      if (!(cpy[i] = strdup(tab[j++])))
	return (NULL);
      ++i;
    }
  cpy[i] = NULL;
  free_tab(tab);
  return (cpy);
}
