/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 04:53:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/18 02:38:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PILE_H
# define FT_PILE_H

# include "libft.h"

typedef struct s_pile
{
	int				value;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

typedef struct s_stacks
{
	t_pile			*a;
	t_pile			*b;
}					t_stacks;

t_pile				*ft_create_elem(int data);
void				ft_pile_clear(t_pile *begin_pile);
void				ft_pile_push_back(t_pile **begin_pile, int value);
int					ft_pile_contain(t_pile *piles, int value);
int					ft_pile_push_back_if_not(t_pile **begin_pile, int value);
void				ft_pile_push_front(t_pile **begin_pile, int data);
int					ft_pile_size(t_pile *begin_pile);
void				ft_pile_print(t_pile *lst);
void				ft_clear_stacks(t_stacks stacks);
t_pile				*ft_pile_sort_insert(t_pile *pile);

#endif
