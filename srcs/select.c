#include "ft_select.h"

static t_arg	*new_arg(char *value)
{
	t_arg	*new;

	if ((new = (t_arg*)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	new->value = value;
	new->is_mark = 0;
	new->color = get_type_color(get_type(value));
	new->size = ft_strlen(value);
	new->next = new;
	new->prev = new;
	return (new);
}

static t_arg	*add_arg(t_arg *args, t_arg *new)
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

static t_select	*new_select()
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

t_select	*get_select(char **input)
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
		args = add_arg(args, new);
		select->args_size++;
	}
	select->args = args;
	select->active_arg = args;
	return (select);
}
