/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:05:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/10 21:36:01 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			ft_in_range(int value, t_range range)
{
	if (value >= range.min && value <= range.max)
		return (1);
	return (0);
}

static int			ft_find_range(t_pile *pile, t_range range)
{
	t_pile	*tmp;
	t_pile	*tmp_rev;

	tmp = pile;
	tmp_rev = pile->prev;
	while (1)
	{
		if (tmp->value >= range.min && tmp->value <= range.max)
			return (1);
		if (tmp_rev->value >= range.min && tmp_rev->value <= range.max)
			return (0);
		tmp = tmp->next;
		tmp_rev = tmp_rev->prev;
	}
}

static int			ft_find_value(t_pile *pile, int value)
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
			if (ft_in_range(piles->a->value, data.segments[i]))
			{
				ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
				j++;
			}
			else if (ft_find_range(piles->a, data.segments[i]))
				while (!ft_in_range(piles->a->value, data.segments[i]))
					ft_push_back_sort(&sort_list, ft_ra(piles), NULL);
			else
				while (!ft_in_range(piles->a->value, data.segments[i]))
					ft_push_back_sort(&sort_list, ft_rra(piles), NULL);
		}
		i++;
	}
	return (sort_list);
}

t_sort_list			*ft_sort_pile(t_stacks *piles, t_pile_data data)
{
	t_pile		*pile_sorted;
	t_sort_list	*sort_list;

	sort_list = ft_split_segments(piles, data);
	pile_sorted = ft_pile_sort_insert(piles->b);
	pile_sorted = pile_sorted->prev;
	while (piles->b)
	{	
		if (piles->b->value == pile_sorted->value)
		{
			ft_push_back_sort(&sort_list, ft_pa(piles), NULL);
			pile_sorted = pile_sorted->prev;
		}
		else if (ft_find_value(piles->b, pile_sorted->value))
			while (piles->b->value != pile_sorted->value)
				ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
		else
			while (piles->b->value != pile_sorted->value)
				ft_push_back_sort(&sort_list, ft_rrb(piles), NULL);
	}
	ft_pile_clear(pile_sorted);
	return (sort_list);
}
