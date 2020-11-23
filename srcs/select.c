/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:02:18 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/22 18:50:16 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			free_select(void)
{
	t_arg	*args;
	t_arg	*last;
	t_arg	*tmp;

	if (g_select)
	{
		args = g_select->args;
		if (args)
		{
			last = args->prev;
			while (args && args != last)
			{
				tmp = args;
				args = args->next;
				free(tmp->value);
				free(tmp);
			}
			free(last->value);
			free(last);
		}
		free(g_select);
	}
}

static t_select	*new_select(void)
{
	t_select	*select;

	if ((select = (t_select*)malloc(sizeof(t_select))) == NULL)
		return (NULL);
	select->active_arg = NULL;
	select->args = NULL;
	select->colum_size = 0;
	select->args_size = 0;
	select->mark_size = 0;
	return (select);
}

t_select		*get_select(t_usym **input)
{
	t_select	*select;
	t_arg		*args;
	t_arg		*new;
	int			i;

	if ((select = new_select()) == NULL)
		return (NULL);
	args = NULL;
	i = -1;
	while (input[++i])
	{
		new = new_arg(input[i]);
		if (select->colum_size < new->size)
			select->colum_size = new->size;
		new->position = i;
		args = add_arg(args, new);
		select->args_size++;
	}
	select->args = args;
	select->active_arg = args;
	return (select);
}
