#include "ft_select.h"

int			ft_color(char *type)
{
	int	i;

	i = -1;
	while (type_colors[++i].type)
	{
		if (ft_strcmp(ft_tolower(type), type_colors[i].type) == 0)
			return (type_colors[i].color);
	}
	return (0);
}

int			get_color(char *str)
{
	int		i;
	int		size;
	char	*type;

	type = NULL;
	if (str)
	{
		size = ft_strlen(str);
		i = -1;
		while (++i < size)
		{
			if (str[i] == '.')
			{
				type = ft_strsub(str, i + 1, size - i - 1);
			}
		}
	}
	if (!type)
		return (0);
	return (ft_color(type));
}

t_select	*get_list(char **input)
{
	t_select	*elem;
	t_list		*list;
	t_list		*tmp;
	int			i;

	list = NULL;
	i = -1;
	while (input[++i])
	{
		elem = (t_select*)malloc(sizeof(t_select));
		elem->name = input[i];
		elem->mark = 0;
		elem->size = ft_strlen(input[i]);
		elem->color = get_color(input[i]);

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
