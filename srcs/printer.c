/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:02:12 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/20 18:23:48 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_selected(t_select *select)
{
	t_arg	*args;

	args = select->args;
	while (1)
	{
		if (args->is_mark)
		{
			write(1, args->value, args->size);
			write(1, " ", 1);
		}
		args = args->next;
		if (args == select->args)
			break ;
	}
}

static void	print_nchars(char c, int counts)
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

static void	print_color(char *color)
{
	write(g_tty_fd, color, ft_strlen(color));
}

static void	print_arg(t_arg *arg, int colum_size)
{
	print_color(arg->color ? arg->color : get_color("white"));
	write(g_tty_fd, arg->value, arg->size);
	print_color(get_color("normal"));
	print_nchars(' ', colum_size - arg->size + 1);
}

t_arg		*get_arg_n(int n)
{
	t_arg	*tmp;

	if (n <= 0 || n > g_select->args_size)
		return (g_select->args);
	tmp = g_select->args;
	while(n--)
		tmp = tmp->next;
	return (tmp);
}

t_arg		*get_begin_arg(int w_cols, int w_lines)
{
	int	b_pos;
	int	a_col;
	int	a_line;
	int	a_pos;
	int	w_elems;

	if (g_select->active_arg->position + 1 > w_cols * w_lines)
	{
		a_pos = g_select->active_arg->position;
		a_col = a_pos % w_cols;
		a_line = a_pos / w_cols + 1;
		w_elems = w_lines * w_cols;
		b_pos = a_pos - a_col - (w_elems - w_cols);
		return (get_arg_n(b_pos));
	}
	return (g_select->args);
}

int			count_printed(t_arg *first_arg,  int nums)
{
	int	first;
	int	size;

	first = first_arg->position;
	size = g_select->args_size;
	return (MIN(size - first, nums));
}

int			print_args(void)
{
	int		cmd_cols;
	int		cmd_lines;
	int		i;
	t_arg	*args;
	int		count;

	tputs(g_term->cl, 1, print_char);
	cmd_cols = get_colums(g_select->colum_size);
	cmd_lines = get_lines();

	if (cmd_cols <= 0 || cmd_lines <= 0)
	{
		write(g_tty_fd, "NO SPACE\nPRESS ESC\nTO EXIT", 26);
		return (1);
	}
	args = get_begin_arg(cmd_cols, cmd_lines);
	count = count_printed(args, cmd_cols * cmd_lines);

	i = -1;
	while (++i < count)
	{
		if (args == g_select->active_arg)
			print_color(get_color("underline"));
		if (args->is_mark)
			print_color(get_color("inverse"));
		print_arg(args, g_select->colum_size);
		if ((i + 1) % cmd_cols == 0 && i != (count - 1))
			write(g_tty_fd, "\n", 1);
		args = args->next;
		// if (args == g_select->args)
		// 	break ;
	}
	return (0);
}
