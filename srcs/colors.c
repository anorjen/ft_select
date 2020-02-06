#include "colors.h"

char	*get_color(char *color_name)
{
	int	i;

	if (color_name)
	{
		i = -1;
		while (g_colors[++i])
		{
			if (ft_strcmp(color_name, g_colors[i].name) == 0)
				return (g_colors[i].color);
		}
	}
	return (NULL);
}

char	*get_type_color_name(char *type)
{
	int	i;

	if (type)
	{
		i = -1;
		while (g_type_colors[++i])
		{
			if (ft_strcmp(type, g_type_colors[i].name) == 0)
				return (g_colors[i].color);
		}
	}
	return (NULL);
}

char	*get_type_color(char *type)
{
	char	*color_name;

	color_name = get_type_color_name(type);
	return (get_color(color_name));
}
