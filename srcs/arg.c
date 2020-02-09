#include "ft_select.h"

t_arg	*new_arg(char *value)
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
