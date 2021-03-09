/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_push_back_if_not.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 06:31:38 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/08 15:07:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

int	ft_pile_push_back_if_not(t_pile **begin_pile, int value)
{
	t_pile	*tmp;

	tmp = *begin_pile;
	if (!tmp)
		*begin_pile = ft_create_elem(value);
	else
	{
		while (tmp->next)
		{
			if (tmp->value == value)
				return (0);
			tmp = tmp->next;
		}
		if (tmp->value == value)
			return (0);
		tmp->next = ft_create_elem(value);
	}
	return (1);
}
