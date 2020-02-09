/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:14 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/09 22:01:15 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_color	g_colors[12] = {
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

static t_color	g_type_colors[6] = {
	{"c", "blue"},
	{"h", "cyan"},
	{"o", "green"},
	{"pdf", "red"},
	{"doc", "yellow"},
	{NULL, NULL}
};

char			*get_color(char *color_name)
{
	int	i;

	if (color_name)
	{
		i = -1;
		while (g_colors[++i].name)
		{
			if (ft_strcmp(color_name, g_colors[i].name) == 0)
				return (g_colors[i].color);
		}
	}
	return (NULL);
}

char			*get_type_color_name(char *type)
{
	int	i;

	if (type)
	{
		i = -1;
		while (g_type_colors[++i].name)
		{
			if (ft_strcmp(type, g_type_colors[i].name) == 0)
				return (g_type_colors[i].color);
		}
	}
	return (NULL);
}

char			*get_type_color(char *type)
{
	char	*color_name;

	color_name = get_type_color_name(type);
	return (get_color(color_name));
}
