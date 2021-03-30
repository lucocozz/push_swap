/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:05:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/30 13:23:23 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_back(t_stacks *piles, t_sort_list *sort_list, int i)
{
	if (i > 0)
	{
		ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
		ft_rotate_back(piles, sort_list, i - 1);
		ft_push_back_sort(&sort_list, ft_rrb(piles), NULL);
	}
	if (i == 0)
		ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
}

static void	ft_rotate_front(t_stacks *piles, t_sort_list *sort_list, int i)
{
	if (i > 0)
	{
		ft_push_back_sort(&sort_list, ft_rrb(piles), NULL);
		ft_rotate_front(piles, sort_list, i - 1);
		ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
	}
	if (i == 0)
	{
		ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
		ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
	}
}

t_sort_list	*ft_insert_sort(t_stacks *piles, t_pile_data data)
{
	int			i;
	int			j;
	int			size;
	t_pile		*tmp;
	t_pile		*tmp_rev;
	t_sort_list	*sort_list;

	size = 1;
	sort_list = NULL;
	ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
	while (piles->a)
	{
		i = 0;
		j = 0;
		tmp = piles->b;
		tmp_rev = piles->b->prev;
		if (piles->a->value == data.min)
		{
			ft_push_back_sort(&sort_list, ft_pb(piles), NULL);
			ft_push_back_sort(&sort_list, ft_rb(piles), NULL);
		}
		else
		{
			while (piles->a->value < tmp->value)
			{
				tmp = tmp->next;
				if (tmp == piles->b)
					break;
				i++;
			}
			while (piles->a->value > tmp_rev->value)
			{
				tmp_rev = tmp_rev->prev;
				if (tmp_rev == piles->b->prev)
					break;
				j++;
			}
			if (j < i && i != 0)
				ft_rotate_front(piles, sort_list, j);
			else
				ft_rotate_back(piles, sort_list, i);
		}
		size++;
	}
	return (sort_list);
}
