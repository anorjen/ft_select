/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_termcap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:59:59 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/06 16:37:36 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_keypress(void)
{
	struct termios	new_settings;

	tcgetattr(0, &g_stored_settings);
	new_settings = g_stored_settings;
	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings);
}

void	reset_keypress(void)
{
	tcsetattr(0, TCSANOW, &g_stored_settings);
}

char	*get_termcap(void)
{
	char	*term;
	char	*term_edit;

	if ((term = ft_strnew(2048)))
	{
		if ((term_edit = ft_strdup(get_env("TERM"))))
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
	g_term->le = tgetstr("le", &termcap);
	g_term->nd = tgetstr("nd", &termcap);
	g_term->cd = tgetstr("cd", &termcap);
	g_term->dc = tgetstr("dc", &termcap);
	g_term->im = tgetstr("im", &termcap);
	g_term->ei = tgetstr("ei", &termcap);
	g_term->so = tgetstr("so", &termcap);
	g_term->se = tgetstr("se", &termcap);
	g_term->up = tgetstr("up", &termcap);
	g_term->do_ = tgetstr("do", &termcap);
	g_term->cl = tgetstr("cl", &termcap);
}

void	set_termcap(char **env)
{
	char	*termcap;

	env = NULL;
	termcap = get_termcap();
	if (termcap)
	{
		set_termenv(termcap);
	}
}
