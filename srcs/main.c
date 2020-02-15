/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:02:02 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/15 22:39:41 by anorjen          ###   ########.fr       */
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
	int			rd;

	status = 1;
	pr_status = 0;

	while (1)
	{
		// write (1, "main_loop: 1\n", 13);
		// write (1, "\n", 1);
		pr_status = print_args();
		
		// write (1, "main_loop: ", 11);
		// write (1, ft_itoa(pr_status), ft_strlen(ft_itoa(pr_status)));
		// write (1, "\n", 1);
		
		key = 0;
		rd = read(0, &key, 8);

		// write (1, ft_itoa(key), ft_strlen(ft_itoa(key)));
		// write (1, "2\n", 2);
		// write (1, "\n", 1);
		
		i = -1;
		while (g_key_actions[++i].key != ZERO)
		{
			// write(1, "3\n", 2);
			if (g_key_actions[i].key == key && (pr_status == 0 || key == ESC))
			{
				write(1, "4\n", 2);
				status = g_key_actions[i].action(g_select);
				break ;
			}
		}
		// write (1, ft_itoa(status), ft_strlen(ft_itoa(status)));
		// write (1, "\n", 1);
		if (pr_status == 1 || status <= 0)
		{
			// write(1, "5\n", 2);
			return (pr_status > status ? pr_status : status);
		}
		// write(1, "6\n", 2);
	}
}

int				main(int ac, char **av)
{
	char		**input;
	int			status;
	// int			fd;

	// close(2);
	// fd = open("author", O_RDONLY);

	if (isatty(0) == 0)
	{
		write (2, "is not tty\n", 11);
		return (1);
	}
	status = 0;
	// write(1, ft_itoa(fd), ft_strlen(ft_itoa(fd)));
	// status = write (fd, "11\n", 3);
	// write(1, ft_itoa(status), ft_strlen(ft_itoa(status)));
	// write (1, "-1\n", 2);
	if (ac == 1)
		input = read_input();
	else
		input = get_input(ac, av);
	if (!input || (g_select = get_select(input)) == NULL
								|| g_select->args == NULL)
		fatal_error(1);
		
	// write(1, input[0], ft_strlen(input[0]));
	
	free(input);
	// write(1, "1\n", 2);
	
	ft_init();
	
	// write(1, "2\n", 2);

	init_signal_handlers();
	
	status = main_loop();
	// write(1, "main status: \n", 14);
	// write(1, ft_itoa(status), ft_strlen(ft_itoa(status)));
	// write(1, "\n", 1);
	
	ft_exit(status);
	// write(1, "main\n", 5);
	return (0);
}
