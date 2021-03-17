/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_contain.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:37:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/15 16:41:13 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pile_contain(t_pile *pile, int value)
{
	t_pile	*tmp;

	tmp = pile;
	while (tmp->next != pile)
	{
		if (tmp->value == value)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->value == value)
		return (0);
	return (1);
}
