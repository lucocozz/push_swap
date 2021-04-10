/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:25:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/10 01:26:17 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "global.h"
# include <stdio.h>

# define FACTOR 50
# define LIMIT FACTOR / 2 - 1

typedef	struct	s_range
{
	int			size;
	int			min;
	int			max;
}				t_range;

typedef struct	s_pile_data
{
	int			size;
	t_range		*segments;
}				t_pile_data;

t_sort_list		*ft_sort_pile(t_stacks *piles, t_pile_data data);

#endif