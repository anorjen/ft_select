#include "ft_select.h"

void			free_select(t_select *select)
{
	t_arg	*args;
	t_arg	*last;
	t_arg	*tmp;

	args = select->args;
	last = args ->prev;
	while (args != last)
	{
		tmp = args;
		args = args->next;
		free(tmp->value);
		free(tmp);
	}
	free(last->value);
	free(last);
	free(select);
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

t_select		*get_select(char **input)
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