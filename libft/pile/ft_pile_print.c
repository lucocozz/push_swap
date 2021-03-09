/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:03:47 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/08 15:13:25 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	ft_pile_print(t_pile *pile)
{
	while (pile)
	{
		ft_putnbr(pile->value);
		ft_putstr(" -> ");
		pile = pile->next;
	}
	ft_putstr("NULL\n");
}
