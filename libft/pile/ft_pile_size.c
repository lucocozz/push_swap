/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:42:33 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/05 18:36:19 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

int	ft_pile_size(t_pile *begin_pile)
{
	int size;

	size = 0;
	while (begin_pile)
	{
		begin_pile = begin_pile->next;
		size++;
	}
	return (size);
}
