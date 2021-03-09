/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:25:41 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/09 00:20:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "global.h"

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

void		ft_sa(t_stacks *pile);
void		ft_sb(t_stacks *pile);
void		ft_ss(t_stacks *pile);
void		ft_pa(t_stacks *pile);
void		ft_pb(t_stacks *pile);
void		ft_ra(t_stacks *pile);
void		ft_rb(t_stacks *pile);
void		ft_rr(t_stacks *pile);
void		ft_rra(t_stacks *pile);
void		ft_rrb(t_stacks *pile);
void		ft_rrr(t_stacks *pile);


#endif