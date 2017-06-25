/*
** gnl.c for palindrome in /home/benoit.pingris/delivery/ADM_palindrome_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Jun 15 10:00:30 2017 benoit pingris
** Last update Thu Jun 15 10:00:31 2017 benoit pingris
*/

#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"

char	*free_ret(char *s)
{
  free(s);
  return (NULL);
}

char	*my_realloc(char *s)
{
  int	i;
  char	*new;

  i = 0;
  while (s[i] != '\0')
    ++i;
  if ((new = malloc(sizeof(char) * (i + READ_SIZE + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s[i] != '\0')
    {
      new[i] = s[i];
      ++i;
    }
  new[i] = '\0';
  free(s);
  return (new);
}

char	get_next_char(int fd)
{
  static char	buff[READ_SIZE + 1];
  static int	len;
  static int	i;
  char		c;

  if (len == 0)
    {
      if ((len = read(fd, buff, READ_SIZE)) == 0)
	return ('\0');
      i = 0;
    }
  c = buff[i];
  ++i;
  --len;
  return (c);
}

char	*get_next_line(int fd)
{
  int	i;
  char	*line;
  char	c;

  i = 0;
  if ((line = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  c = get_next_char(fd);
  while (c != '\n' && c != '\0')
    {
      line[i++] = c;
      c = get_next_char(fd);
      if (i % READ_SIZE == 0)
	{
	  line[i] = '\0';
	  if ((line = my_realloc(line)) == NULL)
	    return (NULL);
	}
    }
  line[i] = '\0';
  if (c == '\0' && line[0] == '\0')
    return (free_ret(line));
  return (line);
}
