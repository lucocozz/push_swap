/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:34:33 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/09 17:04:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "libft.h"

enum					e_sort_list
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
};

typedef struct			s_sort_list
{
	int					value;
	void				(*ft)(t_stacks*);
	struct s_sort_list	*next;
}						t_sort_list;

t_sort_list	*ft_create_sort_list(int value, void (*ft)(t_stacks*));
void		ft_push_back_sort(t_sort_list **sort_list, int value,
				void (*ft)(t_stacks*));
void		ft_clear_sort_list(t_sort_list *sort_list);
void		ft_print_sort_list(t_sort_list *sort_list);
void		ft_sorting(t_stacks *piles, t_sort_list *sort_list);

void		ft_exit_error(t_stacks piles);
t_pile		*ft_parsing(int size, char **numbers);

#endif