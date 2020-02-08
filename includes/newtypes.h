#ifndef NEWTYPES_H
# define NEWTYPES_H
// # include "doing.h"

typedef struct	s_color
{
	char		*name;
	char		*color;
}				t_color;

typedef enum	e_keycode
{
	ZERO = 0,
	ENTER = 10,
	SPACE = 32,
	ESC = 27,
	BACKSPACE = 127,
	UP = 4283163,
	DOWN = 4348699,
	RIGHT = 4414235,
	LEFT = 4479771,
	DELETE = 2117294875L
}				t_keycode;

typedef struct	s_term
{
	char		*cl;
	char		*vi;
	char		*ve;
	char		*ti;
	char		*te;
}				t_term;

typedef struct		s_arg
{
	char			*value;
	int				is_mark;
	char			*color;
	int				size;
	struct s_arg	*prev;
	struct s_arg	*next;
}					t_arg;

typedef struct		s_select
{
	t_arg			*active_arg;
	t_arg			*args;
	int				colum_size;
	int				args_size;
	int				mark_size;
}					t_select;

// //colors.c
// t_color	g_colors[12] = {
// 	{"black", "\033[30m"},
// 	{"red", "\033[31m"},
// 	{"green", "\033[32m"},
// 	{"yellow", "\033[33m"},
// 	{"blue", "\033[34m"},
// 	{"purple", "\033[35m"},
// 	{"cyan", "\033[36m"},
// 	{"white", "\033[37m"},
// 	{"normal", "\033[0m"},
// 	{"inverse", "\033[4m"},
// 	{"underline", "\033[7m"},
// 	{NULL, NULL}
// };

// t_color	g_type_colors[6] = {
// 	{"c", "blue"},
// 	{"h", "cyan"},
// 	{"o", "green"},
// 	{"pdf", "red"},
// 	{"doc", "yellow"},
// 	{NULL, NULL}
// };

typedef int		(*t_spe_key) (t_select *select);

typedef struct	s_action
{
	t_keycode	key;
	t_spe_key	action;
}				t_action;

// t_action	g_key_actions[10] = {
// 	{LEFT, do_left},
// 	{RIGHT, do_right},
// 	{UP, do_up},
// 	{DOWN, do_down},
// 	{SPACE, do_mark},
// 	{ENTER, do_confirm},
// 	{ESC, do_escape},
// 	{DELETE, do_delete},
// 	{BACKSPACE, do_delete},
// 	{ZERO, NULL}
// };

#endif
