/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:02:02 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/23 11:28:18 by anorjen          ###   ########.fr       */
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

static void		check_sym(t_usym **input)
{
	int	i;
	int	j;

	i = -1;
	while (input[++i])
	{
		j = -1;
		while (input[i][++j])
		{
			if (!ft_uisprint(input[i][j]))
			{
				input[i][j] = '?';
			}
		}
	}
}

int				get_input_size(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		++i;
	return (i);
}

static t_usym	**convert2u8(char **input)
{
	int		i;
	int		size;
	t_usym	**res;

	size = get_input_size(input);
	if ((res = (t_usym**)malloc(sizeof(t_usym*) * (size + 1))) == NULL)
		return (NULL);
	res[size] = NULL;
	i = -1;
	while (input[++i])
	{
		res[i] = ft_ctou(input[i]);
	}
	return (res);
}

void			free_input(char **input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		free(input[i]);
	}
	free(input);
	input = NULL;
}

int				main(int ac, char **av)
{
	char		**input;
	t_usym		**u_input;
	int			status;

	status = 0;
	g_tty_fd = get_tty();
	if (ac == 1)
		input = read_input();
	else
		input = get_input(ac, av);
	if (input == NULL)
		fatal_error(1);
	u_input = convert2u8(input);
	free_input(input);
	check_sym(u_input);
	if (!u_input || (g_select = get_select(u_input)) == NULL
								|| g_select->args == NULL)
		fatal_error(1);
	ft_init();
	init_signal_handlers();
	status = main_loop();
	ft_exit(status);
	return (0);
}
