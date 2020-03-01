/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:02:02 by anorjen           #+#    #+#             */
/*   Updated: 2020/03/01 15:43:15 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
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
	return (write(0, &c, 1));
}

int				get_colums(int size)
{
	struct winsize	wins;
	int				err;

	err = ioctl(0, TIOCGWINSZ, &wins);
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
		read(0, &key, 8);
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

int				main(int ac, char **av)
{
	char		**input;
	int			status;

	if (isatty(0) == 0)
		fatal_error(3);
	status = 0;
	if (ac == 1)
		input = read_input();
	else
		input = get_input(ac, av);
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
