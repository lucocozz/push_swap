/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:00:49 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/05 18:35:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	ft_pile_merge(t_pile **begin_pile1, t_pile *begin_pile2)
{
	t_pile *tmp;

	if (*begin_pile1 == NULL)
		*begin_pile1 = begin_pile2;
	else
	{
		tmp = *begin_pile1;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = begin_pile2;
	}
}
