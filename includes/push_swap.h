/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:25:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/28 14:42:13 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "global.h"
# include <stdio.h>

typedef struct	s_pile_data
{
	int			mediane;
	int			min;
	int			max;
}				t_pile_data;

int				ft_is_ascent(t_pile *pile);
int				ft_is_descent(t_pile *pile);
t_sort_list		*ft_insert_sort(t_stacks *piles, t_pile_data data);

#endif