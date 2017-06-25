/*
** useful.h for projtester in /home/benoit.pingris/delivery/github_perso/projTest
** 
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
** 
** Started on  Tue Jun 20 20:44:58 2017 benoit pingris
** Last update Fri Jun 23 12:12:09 2017 benoit pingris
*/

#ifndef USEFUL_H_
# define USEFUL_H_

# include "struct.h"

int	err_file(char *, char *);
int	check_size(char *, char *);
int	disp_file(char *);
int	putstr(char *, int, int);
void	my_putchar(char);

void	showtab(char **);
void	sort_tab(char **);
void	free_tab(char **);
void	free_things(char *, char **);

int	tab_len(char **);
int	set_struct(t_exec *, char *, char *);
int	brackets(char *);
int	is_access(char *, int);

char	*epur_str(char *);
char	*add_brackets(char *);
char	*slash(char *);
char	*mallocat(char *, char *);

char	**get_tab(char *);
char	**add_slash(char **);
char	**str_to_tab(char *, char **);
char	**add_in_array(char **, char *);

#endif /* !USEFUL_H_ */
