/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:37 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/09 22:01:38 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	**get_input(int ac, char **av)
{
	int		i;
	int		size;
	char	**input;

	size = ac - 1;
	input = (char**)malloc(sizeof(char*) * (size + 1));
	input[size] = NULL;
	i = 0;
	while (++i < size + 1)
	{
		input[i - 1] = ft_strdup(av[i]);
	}
	return (input);
}

char	**read_input()
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	char	*str;
	char	*tmp;
	char	**input;

	str = NULL;
	while ((ret = read(0, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
		{
			tmp = str;
			str = ft_strjoin(str, buf);
			free(tmp);
		}
	}
	input = ft_strsplit(str, ' ');
	free(str);
	return (input);
}

char	*get_type(char *value)
{
	int		i;
	int		size;

	if (value)
	{
		size = ft_strlen(value);
		i = size;
		while (--i >= 0)
		{
			if (value[i] == '.' && value[i + 1] != '\0')
				return (&(value[i + 1]));
		}
	}
	return (NULL);
}
