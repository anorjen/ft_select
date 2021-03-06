/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <anorjen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:09 by anorjen           #+#    #+#             */
/*   Updated: 2020/03/14 17:14:38 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	fatal_error(int nbr)
{
	if (nbr == 1)
		write(2, "ft_select: Input ERROR!\n", 24);
	else if (nbr == 2)
		write(2, "ft_select: Termcap ERROR!\n", 26);
	else if (nbr == 3)
		write(2, "ft_select: It is not tty\n", 25);
	else
		write(2, "ft_select: Undefined ERROR!\n", 28);
	free_select();
	exit(1);
}
