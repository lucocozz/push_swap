/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:05:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/27 16:36:12 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			ft_push_to_b(t_stacks *piles, t_sort_list **sort_list,
	t_pile_data data, int seg)
{
	int	j;

	j = 0;
	if (ft_in_range(piles->a->value, data.end))
		ft_push_back_sort(sort_list, ft_ra(piles), NULL);
	if (ft_in_range(piles->a->value, data.segments[seg]))
	{
		ft_push_back_sort(sort_list, ft_pb(piles), NULL);
		j++;
	}
	else if (ft_find_range(piles->a, data.segments[seg]))
		while (!ft_in_range(piles->a->value, data.segments[seg]))
			ft_push_back_sort(sort_list, ft_ra(piles), NULL);
	else
		while (!ft_in_range(piles->a->value, data.segments[seg]))
			ft_push_back_sort(sort_list, ft_rra(piles), NULL);
	return (j);
}

static t_sort_list	*ft_split_segments(t_stacks *piles, t_pile_data data)
{
	int			i;
	int			j;
	t_sort_list	*sort_list;

	i = 0;
	sort_list = NULL;
	while (i < data.size)
	{
		j = 0;
		while (j < data.segments[i].size)
		{
			j += ft_push_to_b(piles, &sort_list, data, i);
		}
		i++;
	}
	return (sort_list);
}

void				ft_sort_three(t_stacks *piles, t_sort_list **sort_list)
{
	while (!ft_is_crescent(piles->a))
	{
		if (piles->a->value > piles->a->next->value)
			ft_push_back_sort(sort_list, ft_sa(piles), NULL);
		else if (piles->a->prev->value < piles->a->next->value)
			ft_push_back_sort(sort_list, ft_rra(piles), NULL);
		else if (piles->a->value > piles->a->prev->value)
			ft_push_back_sort(sort_list, ft_ra(piles), NULL);
	}
}

static void			ft_sort_a(t_stacks *piles, t_sort_list **sort_list,
	t_pile **pile_sorted)
{
	t_pile *sorted;

	sorted = *pile_sorted;
	if (piles->b->value == sorted->value)
	{
		ft_push_back_sort(sort_list, ft_pa(piles), NULL);
		sorted = sorted->prev;
	}
	else if (ft_find_value(piles->b, sorted->value))
		while (piles->b->value != sorted->value)
			ft_push_back_sort(sort_list, ft_rb(piles), NULL);
	else
		while (piles->b->value != sorted->value)
			ft_push_back_sort(sort_list, ft_rrb(piles), NULL);
	*pile_sorted = sorted;
}

t_sort_list			*ft_sort_pile(t_stacks *piles, t_pile_data data)
{
	t_pile		*pile_sorted;
	t_sort_list	*sort_list;

	sort_list = ft_split_segments(piles, data);
	ft_sort_three(piles, &sort_list);
	if (piles->b)
	{
		pile_sorted = ft_pile_sort_insert(piles->b);
		pile_sorted = pile_sorted->prev;
		while (piles->b)
			ft_sort_a(piles, &sort_list, &pile_sorted);
		ft_pile_clear(pile_sorted);
	}
	return (sort_list);
}
