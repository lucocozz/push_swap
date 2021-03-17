/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_push_back_if_not.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 06:31:38 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/15 16:44:27 by lucocozz         ###   ########.fr       */
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
		if (!ft_pile_contain(*begin_pile, value))
			return (0);
		ft_pile_push_back(begin_pile, value);
	}
	return (1);
}
