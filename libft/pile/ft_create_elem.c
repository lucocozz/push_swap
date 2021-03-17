/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:16:54 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/15 16:11:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

t_pile	*ft_create_elem(int value)
{
	t_pile *elem;

	if ((elem = malloc(sizeof(t_pile) * 1)) == NULL)
		return (NULL);
	elem->value = value;
	elem->next = elem;
	elem->prev = elem;
	return (elem);
}
