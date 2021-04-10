/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:05:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/10 01:23:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			ft_in_range(int value, t_range range)
{
	if (value >= range.min && value <= range.max)
		return (1);
	return (0);
}

t_sort_list			*ft_sort_pile(t_stacks *piles, t_pile_data data)
{
	int			i;
	int			j;
	t_sort_list	*sort_list;
	t_pile		*pile_sorted;

	i = 0;
	sort_list = NULL;
	while (i < data.size)
	{
		j = 0;
		while (j < data.segments[i].size)
		{
			if (!ft_in_range(piles->a->value, data.segments[i]))
				ft_push_back_sort(&sort_list, ft_ra(piles), NULL);
			else if (piles->a->value > piles->a->next->value)
				ft_push_back_sort(&sort_list, ft_sa(piles), NULL);
			else if (piles->a->value != data.segments[data.size - 1].max)
			{
				ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
				j++;
			}
			if (piles->b && piles->b->value < piles->b->next->value)
				ft_push_back_sort(&sort_list, ft_sb(piles), NULL);
		}
		i++;
	}
	i--;
	pile_sorted = ft_pile_sort_insert(piles->b);
	while (piles->b)
	{
		if (piles->b->value < piles->b->next->value)
			ft_push_back_sort(&sort_list, ft_sb(piles), NULL);
		else if (piles->b->value != pile_sorted->prev->value)
		{
			if (piles->b->prev->value < piles->b->value && 
			ft_in_range(piles->b->prev->value, data.segments[i]))
			{
				ft_push_back_sort(&sort_list, ft_rrb(piles), NULL);
			}
			else
				ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
		}
		else if (piles->b->prev->value > piles->b->value)
			ft_push_back_sort(&sort_list, ft_rrb(piles), NULL);
		else
		{
			ft_push_back_sort(&sort_list, ft_pa(piles), NULL);
			if (pile_sorted->value == data.segments[i].min && i)
				i--;
			pile_sorted = pile_sorted->prev;
		}
		// ft_pile_print(piles->b);
	}
	ft_pile_clear(pile_sorted);
	return (sort_list);
}
