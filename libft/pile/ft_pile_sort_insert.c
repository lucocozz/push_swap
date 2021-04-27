/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_sort_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:32:51 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/24 00:36:22 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

t_pile	*ft_pile_sort_insert(t_pile *pile)
{
	t_pile	*tmp;
	t_pile	*tmp_sort;
	t_pile	*pile_sort;

	pile_sort = NULL;
	tmp = pile->next;
	ft_pile_push_front(&pile_sort, pile->value);
	while (tmp != pile)
	{
		if (tmp->value < pile_sort->value)
			ft_pile_push_front(&pile_sort, tmp->value);
		else if (tmp->value > pile_sort->prev->value)
			ft_pile_push_back(&pile_sort, tmp->value);
		else
		{
			tmp_sort = pile_sort->next;
			while (tmp->value > tmp_sort->value)
				tmp_sort = tmp_sort->next;
			ft_pile_push_front(&tmp_sort, tmp->value);
		}
		tmp = tmp->next;
	}
	return (pile_sort);
}
