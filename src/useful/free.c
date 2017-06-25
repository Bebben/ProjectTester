/*
** free.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 10:40:48 2017 benoit pingris
** Last update Wed Jun 21 18:16:34 2017 benoit pingris
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

void	free_things(char *s, char **ta)
{
  free(s);
  free_tab(ta);
}
