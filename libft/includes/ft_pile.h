/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 04:53:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/08 16:31:29 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PILE_H
# define FT_PILE_H

# include "libft.h"

typedef struct		s_pile
{
	int				value;
	struct s_pile	*next;
}					t_pile;

typedef	struct		s_stacks
{
	t_pile	*a;
	t_pile	*b;
}					t_stacks;

t_pile				*ft_create_elem(int data);
t_pile				*ft_pile_at(t_pile *begin_pile, unsigned int nbr);
void				ft_pile_clear(t_pile *begin_pile);
t_pile				*ft_pile_last(t_pile *begin_pile);
void				ft_pile_merge(t_pile **begin_pile1, t_pile *begin_pile2);
void				ft_pile_push_back(t_pile **begin_pile, int data);
int					ft_pile_push_back_if_not(t_pile **begin_pile, int value);
void				ft_pile_push_front(t_pile **begin_pile, int data);
void				ft_pile_reverse(t_pile **begin_pile);
int					ft_pile_size(t_pile *begin_pile);
void				ft_pile_print(t_pile *lst);
char				**ft_pile_to_array(t_pile **alst);

#endif
