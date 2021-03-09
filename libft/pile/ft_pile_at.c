/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:54:02 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/05 18:35:22 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

t_pile	*ft_pile_at(t_pile *begin_pile, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	if (!begin_pile)
		return (NULL);
	while (i < nbr && begin_pile->next != NULL)
	{
		begin_pile = begin_pile->next;
		i++;
	}
	return (begin_pile);
}
