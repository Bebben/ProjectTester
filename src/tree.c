/*
** tree.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 10:08:28 2017 benoit pingris
** Last update Fri Jun 23 14:53:32 2017 benoit pingris
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "macro.h"
#include "proj.h"
#include "useful.h"

int		get_len(char *name)
{
  struct dirent	*file;
  DIR		*dir;
  int		i;

  i = 0;
  if (!(dir = opendir(name)))
    return (-FAILURE);
  while ((file = readdir(dir)))
    ++i;
  closedir(dir);
  return (i);
}

char	**get_files(char *name)
{
  DIR		*dir;
  struct dirent	*file;
  int		len;
  char		**tab;
  int		i;

  i = 0;
  if (!(dir = opendir(name)) ||
      (len = get_len(name)) == -FAILURE ||
      !(tab = malloc(sizeof(char *) * (len + 1))))
    return (NULL);
  while ((file = readdir(dir)))
    {
      if (file->d_name[0] != '.')
	tab[i++] = strdup(file->d_name);
    }
  tab[i] = NULL;
  closedir(dir);
  return (tab);
}

void	print_dash(int nb, char *name, int dir)
{
  while (nb > 0)
    {
      putstr(DASHES, SUCCESS, STDOUT_FILENO);
      --nb;
    }
  putstr(name, SUCCESS, STDOUT_FILENO);
  if (name[strlen(name) - 1] != '/' && dir == TRUE)
    my_putchar('/');
  my_putchar('\n');
}

int	my_tree(char *name, char *parent, t_exec *exec)
{
  char		**tab;
  char		*path;
  static int	dash;
  static int	first;
  int		i;

  if ((i = 0) == 0 && (tab = NULL) == NULL &&
      (!(path = mallocat(parent, name)) || !(tab = get_tab(path))))
    return (ERROR);
  if (first++ == 0 && !exec->exec)
    first_dir(name);
  else if (!exec->exec)
    print_dash(dash, name, TRUE);
  ++dash;
  while (tab[i])
    {
      if (is_file(mallocat(path, tab[i])) == 1)
	my_tree(tab[i], path, exec);
      else
	print_find(tab[i], dash, exec, path);
      ++i;
    }
  --dash;
  free_things(path, tab);
  return (SUCCESS);
}
