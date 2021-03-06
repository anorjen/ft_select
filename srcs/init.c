/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:32 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/22 19:52:15 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_init(void)
{
	int			status;

	status = set_termcap();
	if (status)
		fatal_error(2);
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
	free_select();
	close(g_tty_fd);
	exit(status);
}
