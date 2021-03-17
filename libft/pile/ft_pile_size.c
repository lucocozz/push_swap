/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:42:33 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/15 22:16:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

int	ft_pile_size(t_pile *pile)
{
	int		size;
	t_pile	*tmp;

	size = 0;
	tmp = pile->next;
	while (tmp != pile)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}
