/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:42:19 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/23 20:43:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int	ft_sa(t_stacks *piles)
{
	int		value;
	t_pile	*tmp;

	tmp = piles->a;
	value = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = value;
	return (SA);
}

int	ft_sb(t_stacks *piles)
{
	int		value;
	t_pile	*tmp;

	tmp = piles->b;
	value = tmp->value;
	tmp->value = tmp->next->value;
	tmp->next->value = value;
	return (SB);
}

int	ft_ss(t_stacks *piles)
{
	ft_sa(piles);
	ft_sb(piles);
	return (SS);
}

int	ft_pa(t_stacks *piles)
{
	t_pile	*tmp;

	tmp = piles->b;
	if (piles->b)
	{
		ft_pile_push_front(&piles->a, tmp->value);
		if (tmp->next != tmp)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			piles->b = tmp->next;
		}
		else
			piles->b = NULL;
		gc_free(tmp);
		tmp = NULL;
	}
	return (PA);
}

int	ft_pb(t_stacks *piles)
{
	t_pile	*tmp;

	tmp = piles->a;
	if (piles->a)
	{
		ft_pile_push_front(&piles->b, tmp->value);
		if (tmp->next != tmp)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			piles->a = tmp->next;
		}
		else
			piles->a = NULL;
		gc_free(tmp);
		tmp = NULL;
	}
	return (PB);
}
