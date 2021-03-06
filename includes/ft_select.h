/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:56:15 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/22 19:51:45 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include <signal.h>
# include <fcntl.h>

# include "ft_utf8.h"
# include "libft.h"
# include "newtypes.h"

# define BUF_SIZE 100
# define MIN(a, b) ((a) < (b) ? (a) : (b))

int						g_tty_fd;
t_term					*g_term;
t_select				*g_select;
struct termios			g_stored_settings;

/*
** arg.c
*/

void					del_arg(t_arg **arg);
t_arg					*new_arg(t_usym *value);
t_arg					*add_arg(t_arg *args, t_arg *new);

/*
** colors.c
*/

char					*get_color(char *color_name);
char					*get_type_color_name(char *type);
char					*get_type_color(char *type);

/*
** do_action.c
*/

int						do_mark(t_select *select);
int						do_escape(t_select *select);
int						do_delete(t_select *select);
int						do_confirm(t_select *select);

/*
** do_move.c
*/

int						do_left(t_select *select);
int						do_right(t_select *select);
int						do_up(t_select *select);
int						do_down(t_select *select);

/*
** init.c
*/

void					ft_init(void);
void					ft_deinit(void);
void					init_signal_handlers(void);
void					ft_exit(int status);

/*
** input.c
*/

char					**get_input(int ac, char **av);
char					**read_input();
char					*get_type(char *value);

/*
** main.c
*/

int						print_char(int c);
void					ft_init(void);
void					ft_deinit(void);
void					ft_exit(int status);
void					init_signal_handlers(void);

/*
** printer.c
*/

int						print_args(void);

/*
** printer1.c
*/

void					print_selected(t_select *select);
void					print_nchars(char c, int counts);
void					print_color(char *color);
void					print_arg(t_arg *arg, int colum_size);

/*
** select.c
*/

t_select				*get_select(t_usym **input);
void					free_select(void);

/*
** set_termcap.c
*/

char					*get_termcap(void);
int						set_termcap(void);
void					set_termenv(char *termcap);
void					reset_keypress(void);
void					set_keypress(void);

/*
** signal_handler.c
*/

void					signal_handler(int signo);

/*
** fatal_error.c
*/

void					fatal_error(int nbr);

/*
** tty.c
*/

int						get_colums(int size);
int						get_lines(void);
int						get_tty(void);

#endif
