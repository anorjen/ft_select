/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:59:59 by anorjen           #+#    #+#             */
/*   Updated: 2020/03/14 17:15:38 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_keypress(void)
{
	struct termios	new_settings;

	tcgetattr(g_tty_fd, &g_stored_settings);
	new_settings = g_stored_settings;
	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(g_tty_fd, TCSANOW, &new_settings);
}

void	reset_keypress(void)
{
	tcsetattr(g_tty_fd, TCSANOW, &g_stored_settings);
}

char	*get_termcap(void)
{
	char	*term;
	char	*term_edit;

	if ((term = ft_strnew(2048)))
	{
		if ((term_edit = ft_strdup(getenv("TERM"))))
		{
			if (tgetent(term, term_edit) == 1)
			{
				free(term_edit);
				return (term);
			}
			free(term_edit);
		}
		free(term);
	}
	return (NULL);
}

void	set_termenv(char *termcap)
{
	g_term = (t_term *)malloc(sizeof(t_term));
	g_term->cl = tgetstr("cl", &termcap);
	g_term->vi = tgetstr("vi", &termcap);
	g_term->ve = tgetstr("ve", &termcap);
	g_term->ti = tgetstr("ti", &termcap);
	g_term->te = tgetstr("te", &termcap);
}

int		set_termcap(char **env)
{
	char	*termcap;

	env = NULL;
	termcap = get_termcap();
	if (termcap)
	{
		set_termenv(termcap);
		return (0);
	}
	return (1);
}
