/*
** disp.c for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Fri Jun 23 12:11:37 2017 benoit pingris
** Last update Fri Jun 23 12:12:53 2017 benoit pingris
*/

#include <stdlib.h>
#include <unistd.h>
#include "macro.h"
#include "useful.h"

int	err_file(char *path, char *s)
{
  putstr("Can't find the binary \"", ERROR, STDERR_FILENO);
  putstr(s, ERROR, STDERR_FILENO);
  putstr("\" in ", ERROR, STDERR_FILENO);
  putstr(path, ERROR, STDERR_FILENO);
  putstr("\n", ERROR, STDERR_FILENO);
  exit(ERROR);
  return (ERROR);
}
