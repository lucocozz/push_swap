/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:11:26 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/15 22:37:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_ra(t_stacks *piles)
{
	piles->a = piles->a->next;
	return (RA);
}

int	ft_rb(t_stacks *piles)
{
	piles->b = piles->b->next;
	return (RB);
}

int	ft_rr(t_stacks *piles)
{
	ft_ra(piles);
	ft_rb(piles);
	return (RR);
}

int	ft_rra(t_stacks *piles)
{
	piles->a = piles->a->prev;
	return (RRA);
}

int	ft_rrb(t_stacks *piles)
{
	piles->b = piles->b->prev;
	return (RRB);
}
