/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:23:55 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/27 19:55:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile_data	ft_get_pile_data(t_pile *pile)
{
	int			i;
	int			size;
	t_pile_data	data;
	t_pile		*pile_sort;
	t_pile		*tmp_sort;

	i = 0;
	pile_sort = ft_pile_sort_insert(pile);
	data.b.min = pile_sort->value;
	data.a.max = pile_sort->prev->value;
	size = ft_pile_size(pile_sort);
	tmp_sort = pile_sort;
	while (i++ < size / 2)
		tmp_sort = tmp_sort->next;
	data.mediane = tmp_sort->value;
	data.a.min = tmp_sort->value;
	data.b.max = tmp_sort->prev->value;
	ft_pile_clear(pile_sort);
	return (data);
}

static void			ft_split_mediane(t_stacks *piles, t_sort_list **sort_list,
	int mediane)
{
	int	i;
	int	size;

	i = 0;
	size = ft_pile_size(piles->a);
	while (i < size / 2)
	{
		if (piles->a->value < mediane)
		{
			ft_push_back_sort(sort_list, ft_pb(piles), NULL);
			i++;
		}
		else
			ft_push_back_sort(sort_list, ft_ra(piles), NULL);
	}
}

static void			ft_append_list(t_sort_list **sort_list, t_sort_list *next)
{
	t_sort_list *tmp;

	tmp = *sort_list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = next;
}

static t_sort_list	*ft_merge_sort(t_sort_list *sort_a, t_sort_list *sort_b)
{
	t_sort_list	*merge;
	t_sort_list	*tmp_a;
	t_sort_list	*tmp_b;

	merge = NULL;
	tmp_a = sort_a;
	tmp_b = sort_b;
	while (tmp_a != NULL && tmp_b != NULL)
	{
		if ((tmp_a->value == SA && tmp_b->value == SB) && (tmp_a && tmp_b))
			ft_push_back_sort(&merge, SS, NULL);
		else if ((tmp_a->value == RA && tmp_b->value == RB) && (tmp_a && tmp_b))
			ft_push_back_sort(&merge, RR, NULL);
		else if (tmp_a)
			ft_push_back_sort(&merge, tmp_a->value, NULL);
		else if (tmp_b)
			ft_push_back_sort(&merge, tmp_b->value, NULL);
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
	ft_clear_sort_list(sort_a);
	ft_clear_sort_list(sort_b);
	return (merge);
}

int					main(int argc, char **argv)
{
	t_stacks	piles;
	t_pile_data	data;
	t_sort_list	*sort_a;
	t_sort_list	*sort_b;
	t_sort_list	*sort_list;

	piles.b = NULL;
	sort_list = NULL;
	if (argc > 2)
	{
		piles.a = ft_parsing(argc - 1, &argv[1]);
		data = ft_get_pile_data(piles.a);
		ft_split_mediane(&piles, &sort_list, data.mediane);
		sort_a = ft_sort_pile_a(&piles, data.a);
		sort_b = ft_sort_pile_b(&piles, data.b);
		ft_append_list(&sort_list, ft_merge_sort(sort_a, sort_b));
		while (piles.b)
			ft_push_back_sort(&sort_list, ft_pa(&piles), NULL);
		ft_print_sort_list(sort_list);
		ft_clear_sort_list(sort_list);
		ft_clear_stacks(piles);
	}
	return (0);
}