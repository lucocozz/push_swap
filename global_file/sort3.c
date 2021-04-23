/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:12:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/23 15:23:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_rrr(t_stacks *piles)
{
	ft_rra(piles);
	ft_rrb(piles);
	return (RRR);
}

int	ft_is_crescent(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	while (1)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
		if (tmp->next == pile)
			break;
	}
	return (1);
}
