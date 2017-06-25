/*
** get_info.c for projectester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Thu Jun 22 18:56:12 2017 benoit pingris
** Last update Fri Jun 23 13:46:51 2017 benoit pingris
*/

#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "useful.h"
#include "macro.h"
#include "proj.h"
#include "gnl.h"

int	disp_file(char *s)
{
  int	i;

  i = 0;
  while (s[i] && s[i] != '.')
    {
      my_putchar(s[i]);
      ++i;
    }
  return (SUCCESS);
}

char	**get_info(char *s, char *exec)
{
  char	**tab;

  tab = NULL;
  s = strstr(s, ":");
  if (s[0] == ':')
    ++s;
  if (!(tab = str_to_tab(s, tab)) || (!(tab = add_in_array(tab, exec))))
    return (NULL);
  return (tab);
}

int	change_stream(char *path, char *s, int *fd)
{
  s = strstr(s, ":");
  ++s;
  if (s[0] == ' ')
    ++s;
  chdir(path);
  if ((*fd = open(s, O_RDONLY)) == -FAILURE)
    return (err_file(path, s));
  return (SUCCESS);
}

int	check_size(char *path, char *file)
{
  struct stat	st;

  if (stat(path, &st) == -FAILURE)
    return (ERROR);
  if (st.st_size == 0)
    {
      disp_file(file);
      putstr(":\n", SUCCESS, STDOUT_FILENO);
    }
  return (SUCCESS);
}

char	**set_tab(char *s)
{
  char	**tab;

  if (!(tab = malloc(sizeof(char *) * 3)))
    return (NULL);
  if (!(tab[0] = strdup(s)))
    return (NULL);
  tab[1] = NULL;
  return (tab);
}
