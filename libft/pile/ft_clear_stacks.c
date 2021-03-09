/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:12:07 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/09 16:20:52 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pile.h"

void	ft_clear_stacks(t_stacks stacks)
{
	ft_pile_clear(stacks.a);
	ft_pile_clear(stacks.b);
	stacks.a = NULL;
	stacks.b = NULL;
}
