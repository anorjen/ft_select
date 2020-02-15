/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:32 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/15 22:18:48 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_init(void)
{
	extern char	**environ;
	int			status;

	status = set_termcap(environ);
	if (status)
		fatal_error(2);
	set_keypress();
	tputs(g_term->ti, 1, print_char);
	tputs(g_term->vi, 1, print_char);
}

void	ft_deinit(void)
{
	// write (1, "ft_deinit: 1\n", 13);
	reset_keypress();
	// write (1, "ft_deinit: 2\n", 13);
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
	// write (1, "ft_exit: 1\n", 11);
	ft_deinit();
	// write (1, "ft_exit: 2\n", 11);
	if (status == 0)
		print_selected(g_select);
	free_select();
	exit(status);
}
