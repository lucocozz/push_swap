/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:03:47 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/24 00:35:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	ft_pile_print(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile;
	if (tmp)
	{
		while (1)
		{
			ft_putnbr(tmp->value);
			ft_putchar('|');
			tmp = tmp->next;
			if (tmp == pile)
				break ;
		}
	}
	ft_putstr("\n");
}
