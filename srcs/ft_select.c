#include "ft_select.h"

int main(int ac, char **av)
{
	char		**input;
	t_select	select;
	char		*termcap;

	if (ac == 1)
		input = read_input();
	else
		input = get_input(ac, av);

	list = get_list(input);
	term = get_termcap();
	set_termenv(termcap);
	set_keypress();

	main_loop();

	reset_keypress();
	return (0);
}
