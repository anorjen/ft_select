#ifndef COLORS_H
# define COLORS_H
# include "main.h"

typedef struct	s_color
{
	char		*name;
	char		*color;
}				t_color;

t_color	g_colors[12] = {
	{"black", "\033[30m"},
	{"red", "\033[31m"},
	{"green", "\033[32m"},
	{"yellow", "\033[33m"},
	{"blue", "\033[34m"},
	{"purple", "\033[35m"},
	{"cyan", "\033[36m"},
	{"white", "\033[37m"},
	{"normal", "\033[0m"},
	{"inverse", "\033[4m"},
	{"underline" "\033[7m"},
	{NULL, NULL}
};

t_color	g_type_colors[6] = {
	{"c", "blue"},
	{"h", "cyan"},
	{"o", "green"},
	{"pdf", "red"},
	{"doc", "yellow"},
	{NULL, NULL}
};

char	*get_color(char *color_name);
char	*get_type_color_name(char *type);
char	*get_type_color(char *type);

#endif
