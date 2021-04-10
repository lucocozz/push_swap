/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:23:55 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/10 15:17:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_get_segments(t_pile_data *data, t_pile *pile_sort, int size)
{
	int		i;
	int		j;
	t_pile	*tmp_sort;

	i = 0;
	j = 0;
	tmp_sort = pile_sort;
	data->segments[i].min = tmp_sort->value;
	while (1)
	{
		if (j == FACTOR && size >= LIMIT)
		{
			data->segments[i].max = tmp_sort->prev->value;
			data->segments[i].size = j;
			data->segments[++i].min = tmp_sort->value;
			j = 0;
		}
		tmp_sort = tmp_sort->next;
		j++;
		if (tmp_sort == pile_sort)
			break;
	}
	data->segments[i].size = j - 1;
	data->segments[i].max = tmp_sort->prev->value;
}

static t_pile_data	ft_get_pile_data(t_pile *pile)
{
	int			size;
	t_pile_data	data;
	t_pile		*pile_sort;

	pile_sort = ft_pile_sort_insert(pile);
	size = ft_pile_size(pile_sort);
	if (size >= FACTOR)
		data.size = (size / FACTOR) + (size % FACTOR ? 1 : 0);
	else
		data.size = 1;
	data.segments = malloc(sizeof(t_range) * (data.size + 1));
	ft_get_segments(&data, pile_sort, size);
	ft_pile_clear(pile_sort);
	return (data);
}

static t_sort_list	*ft_optimize_sort(t_sort_list *sort_list)
{
	t_sort_list	*tmp;
	t_sort_list	*opti_sort;

	tmp = sort_list;
	opti_sort = NULL;
	while (tmp)
	{
		if (tmp->next && ((tmp->value == RA && tmp->next->value == RB) ||
			(tmp->value == RB && tmp->next->value == RA)))
		{
			ft_push_back_sort(&opti_sort, RR, NULL);
			tmp = tmp->next;
		}
		else if (tmp->next && ((tmp->value == SA && tmp->next->value == SB) ||
			(tmp->value == SB && tmp->next->value == SA)))
		{
			ft_push_back_sort(&opti_sort, SS, NULL);
			tmp = tmp->next;
		}
		else if (tmp->next && ((tmp->value == RRA && tmp->next->value == RRB) ||
			(tmp->value == RRB && tmp->next->value == RRA)))
		{
			ft_push_back_sort(&opti_sort, RRR, NULL);
			tmp = tmp->next;
		}
		else
			ft_push_back_sort(&opti_sort, tmp->value, NULL);
		tmp = tmp->next;
	}
	ft_clear_sort_list(sort_list);
	return (opti_sort);
}

int					main(int argc, char **argv)
{
	int			i;
	t_stacks	piles;
	t_pile_data	data;
	t_sort_list	*sort_list;

	i = 0;
	piles.b = NULL;
	sort_list = NULL;
	if (argc > 2)
	{
		piles.a = ft_parsing(argc - 1, &argv[1]);
		data = ft_get_pile_data(piles.a);
		sort_list = ft_sort_pile(&piles, data);
		sort_list = ft_optimize_sort(sort_list);
		free(data.segments);
		ft_print_sort_list(sort_list);
		// ft_pile_print(piles.a);
		ft_clear_sort_list(sort_list);
		ft_clear_stacks(piles);
	}
	return (0);
}