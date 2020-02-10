/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:02:29 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/10 14:54:44 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	suspend_signal_handler(void)
{
	ft_deinit();
	signal(SIGTSTP, SIG_DFL);
	ioctl(2, TIOCSTI, "\x1A");
}

void		stop_signal_handler(void)
{
	ft_exit(1);
}

void		signal_handler(int signo)
{
	if (signo == SIGTSTP)
		suspend_signal_handler();
	else if (signo == SIGINT || signo == SIGABRT || signo == SIGSTOP
			|| signo == SIGKILL || signo == SIGQUIT)
		stop_signal_handler();
	else if (signo == SIGCONT)
	{
		ft_init();
		init_signal_handlers();
		print_args();
	}
	else if (signo == SIGWINCH)
		print_args();
}
