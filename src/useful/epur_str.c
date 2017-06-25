/*
** epur_str.c for projecttester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 21:15:47 2017 benoit pingris
** Last update Wed Jun 21 22:03:40 2017 benoit pingris
*/

#include <string.h>
#include <stdlib.h>

char	*indent_spaces(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
	str[i] = ' ';
      ++i;
    }
  return (str);
}

char	*epur_str(char *str)
{
  int	i;
  int	h;
  char	*epured;

  h = 0;
  i = 0;
  str = indent_spaces(str);
  if ((epured = calloc(sizeof(char), (strlen(str) + 1))) == NULL)
    return (NULL);
  epured[0] = '\0';
  while (str[i] == ' ')
    ++i;
  while (str[i])
    {
      if (str[i] == ' ')
	epured[h++] = ' ';
      while (str[i] == ' ')
	++i;
      if (str[i] != '\0')
	epured[h++] = str[i++];
    }
  return (epured);
}
