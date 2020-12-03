/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:37 by anorjen           #+#    #+#             */
/*   Updated: 2020/12/03 13:46:01 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char		**get_input(int ac, char **av)
{
	int		i;
	int		j;
	int		size;
	char	**input;

	size = ac - 1;
	if ((input = (char**)malloc(sizeof(char*) * (size + 1))) == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (++i < size + 1)
	{
		if (ft_is_str_empty(av[i]))
			continue ;
		input[j++] = ft_strdup(av[i]);
	}
	while (j < size + 1)
		input[j++] = NULL;
	return (input);
}

static char	*str_join(char *stra, char *strb)
{
	char	*tmp;
	char	*res;

	if (!strb)
		return (stra);
	if (!stra)
		return (ft_strdup(strb));
	tmp = stra;
	res = ft_strjoin(stra, strb);
	free(tmp);
	return (res);
}

char		**read_input(void)
{
	int		ret;
	char	*buf;
	char	*str;
	char	**input;

	str = NULL;
	input = NULL;
	buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1));
	while ((ret = read(0, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = str_join(str, buf);
	}
	if (str)
	{
		input = ft_strspliter(str, " \t\n");
		free(str);
	}
	free(buf);
	return (input);
}

char		*get_type(char *value)
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

void		free_input(char **input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		free(input[i]);
	}
	free(input);
	input = NULL;
}
