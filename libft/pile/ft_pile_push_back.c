/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 06:31:38 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/05 18:46:27 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	ft_pile_push_back(t_pile **begin_pile, int value)
{
	t_pile	*tmp;

	tmp = *begin_pile;
	if (!tmp)
		*begin_pile = ft_create_elem(value);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(value);
	}
}
