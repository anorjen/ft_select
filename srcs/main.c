/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:02:02 by anorjen           #+#    #+#             */
/*   Updated: 2020/03/16 18:56:23 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_action	g_key_actions[10] = {
	{LEFT, do_left},
	{RIGHT, do_right},
	{UP, do_up},
	{DOWN, do_down},
	{SPACE, do_mark},
	{ENTER, do_confirm},
	{ESC, do_escape},
	{DELETE, do_delete},
	{BACKSPACE, do_delete},
	{ZERO, NULL}
};

int				print_char(int c)
{
	return (write(g_tty_fd, &c, 1));
}

int				get_colums(int size)
{
	struct winsize	wins;
	int				err;

	err = ioctl(g_tty_fd, TIOCGWINSZ, &wins);
	if (err != -1)
		return (wins.ws_col / (size + 1));
	return (-1);
}

int				main_loop(void)
{
	t_keycode	key;
	int			i;
	int			status;
	int			pr_status;

	status = 1;
	pr_status = 0;
	while (1)
	{
		pr_status = print_args();
		key = 0;
		read(g_tty_fd, &key, 8);
		i = -1;
		while (g_key_actions[++i].key != ZERO)
		{
			if (g_key_actions[i].key == key && (pr_status == 0 || key == ESC))
			{
				status = g_key_actions[i].action(g_select);
				break ;
			}
		}
		if (status <= 0)
			return (status);
	}
}

int				get_tty(void)
{
	int			i;
	int			tty_fd;
	char		*tty_name;

	tty_name = NULL;
	i = -1;
	while (++i < 3)
	{
		if (isatty(i) != 0)
		{
			tty_name = ttyname(i);
			break ;
		}
	}
	if (tty_name == NULL)
		fatal_error(3);
	if ((tty_fd = open(tty_name, O_RDWR)) == -1)
		fatal_error(3);
	return (tty_fd);
}

static void		check_sym(char **input)
{
	int	i;
	int	j;

	i = -1;
	while (input[++i])
	{
		j = -1;
		while (input[i][++j])
		{
			if (!ft_isprint(input[i][j]))
			{
				input[i][j] = '?';
			}
		}
	}
}

int				main(int ac, char **av)
{
	char		**input;
	int			status;

	status = 0;
	g_tty_fd = get_tty();
	if (ac == 1)
		input = read_input();
	else
		input = get_input(ac, av);
	if (input)
		check_sym(input);
	if (!input || (g_select = get_select(input)) == NULL
								|| g_select->args == NULL)
		fatal_error(1);
	free(input);
	ft_init();
	init_signal_handlers();
	status = main_loop();
	ft_exit(status);
	return (0);
}
