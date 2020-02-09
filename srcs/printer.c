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
	write (1, str, counts);
	free(str);
}

static void	print_color(char *color)
{
	write(1, color, ft_strlen(color));
}

static void	print_arg(t_arg *arg, int colum_size)
{
	print_color(arg->color ? arg->color : get_color("white"));
	write(1, arg->value, arg->size);
	print_color(get_color("normal"));
	print_nchars(' ', colum_size - arg->size + 1);
}

int			print_args()
{
	int	colums;
	int	i;
	t_arg	*args;

	colums = get_colums(g_select->colum_size);
	if (colums <= 0)
		return (-1);
	args = g_select->args;
	tputs(g_term->cl, 1, print_char);
	i = 0;
	while (1)
	{
		++i;
		if (args == g_select->active_arg)
			print_color(get_color("underline"));
		if (args->is_mark)
			print_color(get_color("inverse"));
		print_arg(args, g_select->colum_size);
		if (i % colums == 0)
			write(1, "\n", 1);
		args = args->next;
		if (args == g_select->args)
			break ;
	}
	return (0);
}
