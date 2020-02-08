#include "ft_select.h"

t_color	g_colors[12] = {
	{"black", "\033[30m"},
	{"red", "\033[31m"},
	{"green", "\033[32m"},
	{"yellow", "\033[33m"},
	{"blue", "\033[34m"},
	{"purple", "\033[35m"},
	{"cyan", "\033[36m"},
	{"white", "\033[37m"},
	{"normal", "\033[0m"},
	{"inverse", "\033[7m"},
	{"underline", "\033[4m"},
	{NULL, NULL}
};

t_color	g_type_colors[6] = {
	{"c", "blue"},
	{"h", "cyan"},
	{"o", "green"},
	{"pdf", "red"},
	{"doc", "yellow"},
	{NULL, NULL}
};

t_action	g_key_actions[10] = {
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

void	ft_init()
{
	extern char	**environ;

	set_termcap(environ);
	set_keypress();
	tputs(g_term->ti, 1, print_char);
	tputs(g_term->vi, 1, print_char);
}

int		main_loop(t_select *select)
{
	t_keycode	key;
	int			i;
	int			status;
	int			pr_status;

	while (1)
	{
		tputs(g_term->cl, 1, print_char);
		pr_status = print_args(select);
		key = 0;
		read(0, &key, 8);
		i = -1;
		while (g_key_actions[++i].key != ZERO)
		{
			if (g_key_actions[i].key == key && (pr_status == 0 || key == ESC))
			{
				status = g_key_actions[i].action(select);
				break ;
			}
		}
		if (status <= 0)
			return (status);
	}
}

void	free_select(t_select *select)
{
	t_arg	*args;
	t_arg	*last;
	t_arg	*tmp;

	args = select->args;
	last = args ->prev;
	while (args != last)
	{
		tmp = args;
		args = args->next;
		free(tmp->value);
		free(tmp);
	}
	free(last->value);
	free(last);
	free(select);
}

void	ft_exit(t_select *select, int status)
{
	reset_keypress();
	tputs(g_term->ve, 1, print_char);
	tputs(g_term->te, 1, print_char);
	if (status == 0)
		print_selected(select);
	free_select(select);
	exit(status);
}

int		main(int ac, char **av)
{
	char		**input;
	t_select	*select;
	int			status;

	if (ac == 1)
	{
		input = read_input();
		write(1, input[0], ft_strlen(input[0]));
		write(1, "\n", 1);
		write(1, input[1], ft_strlen(input[1]));
		write(1, "\n", 1);
		write(1, input[2], ft_strlen(input[2]));
		write(1, "\n", 1);
	}
	else
		input = get_input(ac, av);
	if ((select = get_select(input)) == NULL || select->args == NULL)
	{
		write(2, "Input ERROR!\n", 13);
		return (1);
	}
	free(input);
	ft_init();
	status = main_loop(select);
	ft_exit(select, status);
	return (0);
}
