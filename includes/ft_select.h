#ifndef FT_SELECT_H
# define FT_SELECT_H
# include <unistd.h>
# include <termios.h>
# include <term.h>

typedef struct	s_color
{
	char	*type;
	int		color;
}				t_color;

t_color	type_colors[6] = {
	{"c", 1},
	{"h", 2},
	{"txt", 3},
	{"pdf", 4},
	{"doc", 5},
	{NULL, 0}
};

enum keycode
{
	KC_TAB = 9,
	KC_ENTER = 10,
	KC_ESC = 27,
	KC_BS = 127,
	KC_DEL = 1295,
	KC_UP = 1183,
	KC_DOWN = 1184,
	KC_RIGHT = 1185,
	KC_LEFT = 1186,
	KC_HOME = 1190,
	KC_END = 1188
};

typedef int		(*t_spe_key) (t_list *list);

typedef struct	s_actions
{
	int			key;
	t_spe_key	action;

}				t_actions;

t_action	key_actions[] = {
	{KC_LEFT, do_left},
	{KC_RIGHT, do_right},
	{KC_UP, do_up},
	{KC_DOWN, do_down},
	{KC_SPACE, do_mark},
	{KC_ENTER, do_confirm},
	{0, NULL}
};

typedef struct	s_term
{
	char		*le;
	char		*nd;
	char		*cd;
	char		*dc;
	char		*im;
	char		*ei;
	char		*so;
	char		*se;
	char		*up;
	char		*do_;

}				t_term;

typedef struct	s_select
{
	char		*name;
	int			mark;
	int			size;
	int			color;
}				t_select;

t_term			g_term;
static struct termios	g_stored_settings;

char					*get_termcap(void);
void					set_termcap(char **env);
void					set_termenv(char *termcap);
void					reset_keypress(void);
void					set_keypress(void);

#endif
