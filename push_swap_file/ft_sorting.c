/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:05:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/17 22:27:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_ascent(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	while (tmp->next != pile)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_is_descent(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	while (tmp->next != pile)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_sort_list			*ft_sort_pile_a(t_stacks *piles, t_range range)
{
	t_sort_list	*sort_list;

	sort_list = NULL;
	while (1)
	{
		if (piles->a->value == range.min)
			if (ft_is_descent(piles->a))
					return (sort_list);
		if (piles->a->value == range.max)
			ft_push_back_sort(&sort_list, ft_ra(piles), NULL);
		else if (piles->a->value < piles->a->next->value)
			ft_push_back_sort(&sort_list, ft_ra(piles), NULL);
		else
			ft_push_back_sort(&sort_list, ft_sa(piles), NULL);
	}
}

t_sort_list			*ft_sort_pile_b(t_stacks *piles, t_range range)
{
	t_sort_list	*sort_list;

	sort_list = NULL;
	while (1)
	{
		if (piles->b->value == range.max)
			if (ft_is_ascent(piles->b))
					return (sort_list);
		if (piles->b->value == range.min)
			ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
		else if (piles->b->value > piles->b->next->value)
			ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
		else
			ft_push_back_sort(&sort_list, ft_sb(piles), NULL);
	}
}
