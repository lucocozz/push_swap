/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:32:10 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/15 16:17:26 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	ft_pile_push_front(t_pile **begin_pile, int value)
{
	t_pile *new;
	t_pile *tmp;

	tmp = *begin_pile;
	if (!tmp)
		*begin_pile = ft_create_elem(value);
	else
	{
		new = ft_create_elem(value);
		new->next = tmp;
		new->prev = tmp->prev;
		tmp->prev->next = new;
		tmp->prev = new;
		*begin_pile = new;
	}
}
