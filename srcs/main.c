#include "ft_select.h"


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
		input = read_input();
	else
		input = get_input(ac, av);
	if ((select = get_select(input)) == NULL || select->args == NULL)
	{
		write(2, "Input ERROR!\n", 13);
		return (1);
	}
	ft_init();
	status = main_loop(select);
	ft_exit(select, status);
	return (0);
}
