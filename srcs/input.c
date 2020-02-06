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
	while (++i < size)
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
		buf[BUF_SIZE] = '\0';
		if (!str)
		{
			str = ft_strdup(buf);
		}
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

char		*get_type(char *value)
{
	int		i;
	int		size;

	if (value)
	{
		size = ft_strlen(value);
		i = -1;
		while (++i < size)
		{
			if (value[i] == '.' && value[i + 1] != '\0')
				return (&(value[i + 1]));
		}
	}
	return (NULL);
}

t_select	*get_select(char **input)
{
	t_select	*select;
	t_arg		*args;
	t_arg		*new;
	t_arg		*tmp;
	int			i;

	select = (t_select*)malloc(sizeof(t_select));
	select->active_arg = NULL;
	select->args = NULL;
	select->colum_size = 0;
	select->args_size = 0;
	select->mark_size = 0;
	args = NULL;
	i = -1;
	while (input[++i])
	{
		new = (t_arg*)malloc(sizeof(t_arg));
		new->value = input[i];
		new->is_mark = 0;
		new->color = get_type_color(get_type(input[i]));

		tmp = (t_list*)malloc(sizeof(t_list));
		tmp->content = elem;
		tmp->content_size = sizeof(elem);

		if (!list)
		{
			list = tmp;
		}
		else
		{
			ft_lstadd(&list, tmp);
		}
	}
	return (list);
}
