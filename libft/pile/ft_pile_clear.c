/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:12:07 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/05 18:55:03 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	ft_pile_clear(t_pile *begin_pile)
{
	t_pile *prev;

	while (begin_pile)
	{
		prev = begin_pile;
		begin_pile = begin_pile->next;
		free(prev);
	}
}
