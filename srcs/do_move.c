/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:28 by anorjen           #+#    #+#             */
/*   Updated: 2020/02/09 22:01:29 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	do_left(t_select *select)
{
	if (select->active_arg->prev)
		select->active_arg = select->active_arg->prev;
	return (1);
}

int	do_right(t_select *select)
{
	if (select->active_arg->next)
		select->active_arg = select->active_arg->next;
	return (1);
}

int	do_up(t_select *select)
{
	int		colums;
	int		i;
	t_arg	*tmp;

	colums = get_colums(select->colum_size);
	tmp = select->active_arg;
	i = 0;
	while (tmp && i < colums)
	{
		if (tmp == select->args)
			break ;
		tmp = tmp->prev;
		++i;
	}
	if (i == colums)
		select->active_arg = tmp;
	return (1);
}

int	do_down(t_select *select)
{
	int		colums;
	int		i;
	t_arg	*tmp;

	colums = get_colums(select->colum_size);
	tmp = select->active_arg;
	i = 0;
	while (tmp && i < colums)
	{
		if (tmp == select->args->prev)
			break ;
		tmp = tmp->next;
		++i;
	}
	if (i == colums)
		select->active_arg = tmp;
	return (1);
}
