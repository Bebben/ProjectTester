/*
** sort.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 10:50:11 2017 benoit pingris
** Last update Wed Jun 21 10:53:17 2017 benoit pingris
*/

#include <string.h>

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    ++i;
  return (i);
}

void	sort_tab(char **tab)
{
  char	*s;
  int	nb;
  int	i;

  nb = tab_len(tab) * tab_len(tab);
  while (nb != 0)
    {
      i = 0;
      while (tab[i])
	{
	  if (tab[i + 1] && strcmp(tab[i], tab[i + 1]) > 0)
	    {
	      s = tab[i];
	      tab[i] = tab[i + 1];
	      tab[i + 1] = s;
	    }
	  ++i;
	}
      --nb;
    }
}
