/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:09 by anorjen           #+#    #+#             */
/*   Updated: 2020/11/23 11:28:13 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg	*new_arg(t_usym *value)
{
	t_arg	*new;
	char	*str;

	if ((new = (t_arg*)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	new->value = value;
	new->is_mark = 0;
	str = ft_utoc(value);
	new->color = get_type_color(get_type(str));
	free(str);
	new->size = ft_ustrlen(value);
	new->next = new;
	new->prev = new;
	return (new);
}

t_arg	*add_arg(t_arg *args, t_arg *new)
{
	t_arg	*last;

	if (new == NULL)
		return (args);
	if (!args)
	{
		args = new;
	}
	else
	{
		last = args->prev;
		last->next = new;
		new->next = args;
		args->prev = new;
		new->prev = last;
	}
	return (args);
}

void	del_arg(t_arg **arg)
{
	t_arg	*before;
	t_arg	*after;

	before = (*arg)->prev;
	after = (*arg)->next;
	before->next = after;
	after->prev = before;
	free((*arg)->value);
	free(*arg);
	*arg = NULL;
}
