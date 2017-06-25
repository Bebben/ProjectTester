/*
** find.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 18:10:34 2017 benoit pingris
** Last update Fri Jun 23 16:34:58 2017 benoit pingris
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "macro.h"
#include "useful.h"
#include "proj.h"

char	*find_path(char **envp)
{
  int	i;

  i = 0;
  while (envp[i])
    {
      if (strncmp(envp[i], "PATH=", 5) == SAME)
	return (&envp[i][5]);
      ++i;
    }
  return (NULL);
}

static char	**path_tab(char *s)
{
  char		**tab;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  if (!(tab = malloc(sizeof(char *) * (strlen(s) + 2))))
    return (NULL);
  while (i < (int)strlen(s))
    {
      k = 0;
      if (!(tab[j] = malloc(sizeof(char) * (strlen(s) + 1))))
	return (NULL);
      while (s[i] && s[i] != ':')
	tab[j][k++] = s[i++];
      tab[j++][k] = '\0';
      ++i;
    }
  tab[j] = NULL;
  if (!(tab = add_slash(tab)))
    return (NULL);
  return (tab);
}

int	recur_path(char *path, char *target)
{
  DIR		*dir;
  struct dirent	*file;

  if (!(dir = opendir(path)))
    return (ERROR);
  while ((file = readdir(dir)))
    {
      if (strcmp(target, file->d_name) == SAME)
	{
	  if (is_access(mallocat(path, file->d_name), 0) == 0)
	    return (SUCCESS);
	  else
	    return (ERROR);
	}
    }
  closedir(dir);
  return (ERROR);
}

int	find_in_path(char *s, char **envp)
{
  char	*path;
  char	**tab;
  int	i;
  int	ret;

  i = 0;
  if (!(path = find_path(envp)))
    return (ERROR);
  if (!(tab = path_tab(path)))
    return (ERROR);
  while (tab[i])
    {
      if ((ret = recur_path(tab[i], s)) == SUCCESS)
	{
	  free_tab(tab);
	  return (SUCCESS);
	}
      if (ret == FAILURE)
	return (ERROR);
      ++i;
    }
  free_tab(tab);
  return (ERROR);
}
