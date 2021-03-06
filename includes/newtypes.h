/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:59:36 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/22 18:50:51 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWTYPES_H
# define NEWTYPES_H

typedef struct		s_color
{
	char			*name;
	char			*color;
}					t_color;

typedef enum		e_keycode
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
}					t_keycode;

typedef struct		s_term
{
	char			*cl;
	char			*vi;
	char			*ve;
	char			*ti;
	char			*te;
}					t_term;

typedef struct		s_arg
{
	t_usym			*value;
	int				position;
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

typedef int			(*t_spe_key) (t_select *select);

typedef struct		s_action
{
	t_keycode		key;
	t_spe_key		action;
}					t_action;

#endif
