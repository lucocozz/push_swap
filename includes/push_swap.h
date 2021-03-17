/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:25:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/17 19:12:59 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "global.h"
# include <stdio.h>

typedef	struct	s_range
{
	int			min;
	int			max;
}				t_range;

typedef struct	s_pile_data
{
	int			mediane;
	t_range		a;
	t_range		b;
}				t_pile_data;

int				ft_is_ascent(t_pile *pile);
int				ft_is_descent(t_pile *pile);
t_sort_list		*ft_sort_pile_a(t_stacks *piles, t_range range);
t_sort_list		*ft_sort_pile_b(t_stacks *piles, t_range range);

#endif