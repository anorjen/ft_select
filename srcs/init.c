#include "ft_select.h"

void	ft_init(void)
{
	extern char	**environ;

	set_termcap(environ);
	set_keypress();
	tputs(g_term->ti, 1, print_char);
	tputs(g_term->vi, 1, print_char);
}

void	ft_deinit(void)
{
	reset_keypress();
	tputs(g_term->ve, 1, print_char);
	tputs(g_term->te, 1, print_char);
}

void	init_signal_handlers(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGSTOP, signal_handler);

	signal(SIGWINCH, signal_handler);

	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
}

void	ft_exit(int status)
{
	ft_deinit();
	if (status == 0)
		print_selected(g_select);
	free_select(g_select);
	exit(status);
}
