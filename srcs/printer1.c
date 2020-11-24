/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 18:02:48 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/24 11:32:46 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		print_char(int c)
{
	return (write(g_tty_fd, &c, 1));
}

void	print_selected(t_select *select)
{
	t_arg	*args;

	args = select->args;
	while (1)
	{
		if (args->is_mark)
		{
			uwrite(1, args->value, args->size);
			write(1, " ", 1);
		}
		args = args->next;
		if (args == select->args)
			break ;
	}
}

void	print_nchars(char c, int counts)
{
	char	*str;
	int		i;

	str = ft_strnew(counts);
	i = -1;
	while (++i < counts)
		str[i] = c;
	write(g_tty_fd, str, counts);
	free(str);
}

void	print_color(char *color)
{
	write(g_tty_fd, color, ft_strlen(color));
}

void	print_arg(t_arg *arg, int colum_size)
{
	if (arg == g_select->active_arg)
		print_color(get_color("underline"));
	if (arg->is_mark)
		print_color(get_color("inverse"));
	print_color(arg->color ? arg->color : get_color("white"));
	uwrite(g_tty_fd, arg->value, arg->size);
	print_color(get_color("normal"));
	print_nchars(' ', colum_size - arg->size + 1);
}
