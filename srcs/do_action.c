#include "ft_select.h"

int	do_mark(t_select *select)
{
	select->active_arg->is_mark = (select->active_arg->is_mark ? 0 : 1);
	select->mark_size += (select->active_arg->is_mark ? 1 : -1);
	return (1);
}

int	do_confirm(t_select *select)
{
	(void)select;
	return (0);
}

int	do_escape(t_select *select)
{
	(void)select;
	return (-1);
}

int	do_delete(t_select *select)
{
	t_arg	*tmp;

	select->args_size--;
	if (select->active_arg->is_mark)
		select->mark_size--;
	tmp = select->active_arg;
	select->active_arg = select->active_arg->next;
	if (tmp == select->args)
		select->args = select->active_arg;
	if (tmp == select->active_arg)
		return (-1);
	del_arg(&tmp);
	return (1);
}
