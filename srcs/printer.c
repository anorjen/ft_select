#include "ft_select.h"

int	print_char(int c)
{
	return(write(1, &c, 1));
}

void	print_selected(t_select *select)
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
	{
		str[i] = c;
	}
	write (1, str, counts);
	free(str);
}

int	get_colums(int size)
{
	struct winsize	wins;
	int				err;

	err = ioctl(0, TIOCGWINSZ, &wins);
	if (err != -1)
		return (wins.ws_col / (size + 1));
	return (-1);
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

int	print_args(t_select *select)
{
	int	colums;
	int	i;
	int	colum_size;
	t_arg	*args;

	colum_size = select->colum_size;
	colums = get_colums(colum_size);
	if (colums <= 0)
		return (-1);
	args = select->args;
	i = 0;
	while (1)
	{
		++i;
		if (args == select->active_arg)
			print_color(get_color("underline"));
		if (args->is_mark)
			print_color(get_color("inverse"));
		print_arg(args, colum_size);
		if (i == colums)
		{
			write(1, "\n", 1);
			i = 0;
		}
		args = args->next;
		if (args == select->args)
		{
			break ;
		}
	}
	return (0);
}
