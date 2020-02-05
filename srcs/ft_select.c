
#include "ft_select.h"
#define BUF_SIZE 100

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

int main(int ac, char **av)
{
	char	**input;
	t_list	list;
	char	*termcap;

	if (ac == 1)
	{
		input = read_input();
	}
	else
	{
		input = get_input(ac, av);
	}
	list = get_list(input);
	term = get_termcap();
	set_termenv(termcap);
	set_keypress();

	main_loop();

	reset_keypress();
	return (0);
}
