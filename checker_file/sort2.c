/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:11:26 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/09 18:24:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_stacks *piles)
{
	t_pile *tmp;

	tmp = piles->a;
	if (ft_pile_size(piles->a) > 1)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		ft_pile_push_front(&piles->a, tmp->next->value);
		free(tmp->next);
		tmp->next = NULL;
	}
}

void	ft_rb(t_stacks *piles)
{
	t_pile *tmp;

	tmp = piles->b;
	if (ft_pile_size(piles->b) > 1)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		ft_pile_push_front(&piles->b, tmp->next->value);
		free(tmp->next);
		tmp->next = NULL;	
	}
}

void	ft_rr(t_stacks *piles)
{
	ft_ra(piles);
	ft_rb(piles);	
}

void	ft_rra(t_stacks *piles)
{
	t_pile *tmp;

	tmp = piles->a;
	if (ft_pile_size(piles->a) > 1)
	{
		ft_pile_push_back(&piles->a, tmp->value);
		piles->a = tmp->next;
		free(tmp);
		tmp = NULL;	
	}
}

void	ft_rrb(t_stacks *piles)
{
	t_pile *tmp;

	tmp = piles->b;
	if (ft_pile_size(piles->b) > 1)
	{
		ft_pile_push_back(&piles->b, tmp->value);
		piles->b = tmp->next;
		free(tmp);
		tmp = NULL;		
	}
}