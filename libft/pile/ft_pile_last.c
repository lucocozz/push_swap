/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:51:16 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/05 18:35:37 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

t_pile	*ft_pile_last(t_pile *begin_pile)
{
	while (begin_pile->next != NULL)
		begin_pile = begin_pile->next;
	return (begin_pile);
}
