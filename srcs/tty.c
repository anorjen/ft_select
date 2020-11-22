/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:56:47 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/22 17:57:28 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				get_lines(void)
{
	struct winsize	wins;
	int				err;

	err = ioctl(g_tty_fd, TIOCGWINSZ, &wins);
	if (err != -1)
		return (wins.ws_row);
	return (-1);
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
