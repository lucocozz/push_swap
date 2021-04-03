/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:25:04 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/03 17:03:45 by lucocozz         ###   ########.fr       */
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
	int			size;
	int			origin;
	t_pile		*head;
}				t_pile_data;

typedef struct	s_index
{
	int			i;
	int			j;
	t_pile		*tmp_i;
	t_pile		*tmp_j;
}				t_index;

int				ft_is_ascent(t_pile *pile);
int				ft_is_descent(t_pile *pile);
t_sort_list		*ft_insert_sort(t_stacks *piles, t_pile_data data);
void			ft_append_list(t_sort_list **sort_list, t_sort_list *next);
t_index			ft_get_insert_pos(t_stacks *piles);

#endif