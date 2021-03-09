/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 21:44:16 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/05 18:36:12 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	ft_pile_reverse(t_pile **begin_pile)
{
	t_pile *prev;
	t_pile *next;
	t_pile *curr;

	prev = 0;
	curr = *begin_pile;
	if (!curr || !curr->next)
		return ;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*begin_pile = prev;
}
