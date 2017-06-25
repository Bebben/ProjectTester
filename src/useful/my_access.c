/*
** my_access.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 20:44:00 2017 benoit pingris
** Last update Thu Jun 22 11:54:17 2017 benoit pingris
*/

#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "useful.h"
#include "macro.h"

int	is_access(char *s, int fr)
{
  int	ret;

  ret = ERROR;
  if (access(s, X_OK) == 0)
    ret = SUCCESS;
  if (fr == SUCCESS)
    free(s);
  return (ret);
}

int	is_file(char *name)
{
  struct stat	st;

  stat(name, &st);
  free(name);
  return (S_ISDIR(st.st_mode));
}

void	first_dir(char *s)
{
  int	i;

  i = strlen(s) - 2;
  while (i > 0 && s[i] != '/')
    --i;
  if (s[i] == '/')
    ++i;
  putstr(&s[i], SUCCESS, STDOUT_FILENO);
  if (s[strlen(s) - 1] != '/')
    my_putchar('/');
  my_putchar('\n');
}

