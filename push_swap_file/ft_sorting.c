/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:05:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/03 18:06:16 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_back(t_stacks *piles, t_pile_data data,
t_sort_list *sort_list, t_index index)
{
	if (piles->b != index.tmp_i)
	{
		ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
		ft_rotate_back(piles, data, sort_list, index);
		if (piles->a)
		{
			index = ft_get_insert_pos(&(t_stacks){piles->a, data.head});
			if (index.tmp_i == piles->b)
				ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
		}
		ft_push_back_sort(&sort_list, ft_rrb(piles), NULL);
	}
	else
		ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
}

static void	ft_rotate_front(t_stacks *piles, t_pile_data data,
t_sort_list *sort_list, t_index index)
{
	if (piles->b->prev != index.tmp_j)
	{
		ft_push_back_sort(&sort_list, ft_rrb(piles), NULL);
		ft_rotate_front(piles, data, sort_list, index);
		if (piles->a && piles->a->value != data.min)
		{
			index = ft_get_insert_pos(&(t_stacks){piles->a, data.head});
			if (index.tmp_j == piles->b->prev)
			{
				ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
				ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
			}
		}
		ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
	}
	else
	{
		ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
		ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
	}
}

t_index		ft_get_insert_pos(t_stacks *piles)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	index.tmp_i = piles->b;
	index.tmp_j = piles->b->prev;
	while (piles->a->value < index.tmp_i->value)
	{
		index.tmp_i = index.tmp_i->next;
		if (index.tmp_i == piles->b)
		{
			index.tmp_i = index.tmp_i->prev;
			break;
		}
		index.i++;
	}
	while (piles->a->value > index.tmp_j->value)
	{
		index.tmp_j = index.tmp_j->prev;
		if (index.tmp_j == piles->b->prev)
		{
			index.tmp_j = index.tmp_j->next;
			break;
		}
		index.j++;
	}
	return (index);
}

t_sort_list	*ft_insert_sort(t_stacks *piles, t_pile_data data)
{
	t_index		index;
	t_sort_list	*sort_list;

	data.size = 1;
	sort_list = NULL;
	ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
	ft_pile_print(piles->b);
	while (piles->a)
	{
		data.head = piles->b;
		if ((piles->a->value == data.min) || (data.size == 1
			&& piles->a->value < piles->b->value))
		{
			ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
			ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
		}
		else
		{
			index = ft_get_insert_pos(piles);
			if (index.j < index.i && index.i != 0)
				ft_rotate_front(piles, data, sort_list, index);
			else
				ft_rotate_back(piles, data, sort_list, index);
		}
		data.size++;
		ft_pile_print(piles->b);
	}
	return (sort_list);
}
