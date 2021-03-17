/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:12:07 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/15 21:30:44 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	ft_pile_clear(t_pile *pile)
{
	t_pile	*tmp;
	t_pile	*next;

	if (pile)
	{
		tmp = pile->next;
		while (tmp != pile)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		free(pile);
	}
}
