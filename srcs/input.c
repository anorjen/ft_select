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
	char	*str;
	char	**input;

	str = NULL;
	get_next_line(0, &str);
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
