#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "main.h"
# include <termios.h>
# include <term.h>

#define BUF_SIZE 100

typedef enum	e_keycode
{
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

typedef int		(*t_spe_key) (t_select *select);

typedef struct	s_actions
{
	long		key;
	t_spe_key	action;
}				t_actions;

t_action	key_actions[7] = {
	{LEFT, do_left},
	{RIGHT, do_right},
	{UP, do_up},
	{DOWN, do_down},
	{SPACE, do_mark},
	{ENTER, do_confirm},
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
	char		*cl;
}				t_term;

typedef struct		s_arg
{
	char			*value;
	int				is_mark;
	char			*color;
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

t_term					g_term;
static struct termios	g_stored_settings;

char					*get_termcap(void);
void					set_termcap(char **env);
void					set_termenv(char *termcap);
void					reset_keypress(void);
void					set_keypress(void);

#endif
