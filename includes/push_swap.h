/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:25:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/18 02:40:07 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "global.h"
# include <stdio.h>

typedef enum e_direction
{
	BACK,
	FRONT
}				t_direction;

typedef struct s_range
{
	int			size;
	int			min;
	int			max;
}				t_range;

typedef struct s_index
{
	int			index;
	t_direction	dir;

}				t_index;

typedef struct s_insert
{
	int			min;
	t_index		pos;
	t_index		value;

}				t_insert;

typedef struct s_pile_data
{
	int			size;
	t_range		end;
	t_range		*segments;
}				t_pile_data;

typedef struct s_data_pos
{
	int			value;
	t_index		val;
}				t_data_pos;

typedef struct s_count
{
	int	i;
	int	j;
	int	k;
}				t_count;

t_sort_list		*ft_sort_pile(t_stacks *piles, t_pile_data data);
t_insert		ft_find_insert(t_stacks *piles);
int				ft_in_range(int value, t_range range);
int				ft_find_value(t_pile *pile, int value);
int				ft_find_range(t_pile *pile, t_range range);

#endif
