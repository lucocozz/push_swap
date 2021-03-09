/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 23:42:19 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/09 18:38:52 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_stacks *piles)
{
	int		value;
	t_pile	*tmp;

	tmp = piles->a;
	if (ft_pile_size(piles->a) > 1)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		value = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = value;
	}
}

void	ft_sb(t_stacks *piles)
{
	int		value;
	t_pile	*tmp;

	tmp = piles->b;
	if (ft_pile_size(piles->b) > 1)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		value = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = value;
	}
}

void	ft_ss(t_stacks *piles)
{
	ft_sa(piles);
	ft_sb(piles);
}

void	ft_pa(t_stacks *piles)
{
	t_pile	*tmp;

	tmp = piles->b;
	if (ft_pile_size(piles->b) > 1)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		ft_pile_push_back(&piles->a, tmp->next->value);
		free(tmp->next);
		tmp->next = NULL;
	}
	else if (piles->b != NULL)
	{
		ft_pile_push_back(&piles->a, piles->b->value);
		free(piles->b);
		piles->b = NULL;
	}
}

void	ft_pb(t_stacks *piles)
{
	t_pile	*tmp;

	tmp = piles->a;
	if (ft_pile_size(piles->a) > 1)
	{
		while (tmp->next->next)
			tmp = tmp->next;
		ft_pile_push_back(&piles->b, tmp->next->value);
		free(tmp->next);
		tmp->next = NULL;
	}
	else if (piles->a != NULL)
	{
		ft_pile_push_back(&piles->b, piles->a->value);
		free(piles->a);
		piles->a = NULL;
	}
}
