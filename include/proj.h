/*
** proj.h for projtester in /home/benoit.pingris/delivery/synthesis/ADM_projTester_2016
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Wed Jun 21 10:12:08 2017 benoit pingris
** Last update Fri Jun 23 11:29:36 2017 benoit pingris
*/

#ifndef PROJ_H_
# define PROJ_H_

# include "struct.h"

int	my_exec(char **, int, t_exec *);
int	my_parser(t_exec *, char *);
int	my_tree(char *, char *, t_exec *);
int	recu_tree(char *, char *, t_exec *);

int	find_in_path(char *, char **);
int	is_file(char *);
int	print_find(char *, int, t_exec *, char *);
int	change_stream(char *, char *, int *);

void	first_dir(char *);
void	print_dash(int, char *, int);

char	**set_tab(char *);
char	**get_files(char *);
char	**get_info(char *, char *);

#endif /* !PROJ_H_ */
