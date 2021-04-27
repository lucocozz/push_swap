/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:50:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/27 14:52:36 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_in_range(int value, t_range range)
{
	if (value >= range.min && value <= range.max)
		return (1);
	return (0);
}

int	ft_find_range(t_pile *pile, t_range range)
{
	t_pile	*tmp;
	t_pile	*tmp_rev;

	tmp = pile;
	tmp_rev = pile->prev;
	while (1)
	{
		if (ft_in_range(tmp->value, range))
			return (1);
		if (ft_in_range(tmp->value, range))
			return (0);
		tmp = tmp->next;
		tmp_rev = tmp_rev->prev;
	}
}

int	ft_find_value(t_pile *pile, int value)
{
	t_pile	*tmp;
	t_pile	*tmp_rev;

	tmp = pile;
	tmp_rev = pile->prev;
	while (1)
	{
		if (tmp->value == value)
			return (1);
		if (tmp_rev->value == value)
			return (0);
		tmp = tmp->next;
		tmp_rev = tmp_rev->prev;
	}
}
