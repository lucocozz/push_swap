/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:23:55 by lucocozz          #+#    #+#             */
/*   Updated: 2021/04/23 16:39:53 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_get_segments(t_pile_data *data, t_pile *pile_sort, int size,
	int factor)
{
	int		i;
	int		j;
	int		k;
	t_pile	*tmp_sort;

	i = 0;
	j = 0;
	k = 0;
	tmp_sort = pile_sort;
	data->segments[i].min = tmp_sort->value;
	while (k <= size - 3)
	{
		if (j == factor && size >= factor / 2 - 1)
		{
			data->segments[i].max = tmp_sort->prev->value;
			data->segments[i].size = j;
			data->segments[++i].min = tmp_sort->value;
			j = 0;
		}
		tmp_sort = tmp_sort->next;
		j++;
		k++;
	}
	data->segments[i].size = j;
	data->segments[i].max = tmp_sort->prev->value;
	data->end.min = tmp_sort->value;
	data->end.max = pile_sort->prev->value;
}

static t_pile_data	ft_get_pile_data(t_pile *pile)
{
	int			size;
	t_pile_data	data;
	t_pile		*pile_sort;
	int			factor;

	pile_sort = ft_pile_sort_insert(pile);
	size = ft_pile_size(pile_sort);
	factor = (size < 250 ? 15 : 35);
	if (size >= factor)
		data.size = (size / factor) + (size % factor ? 1 : 0);
	else
		data.size = 1;
	data.segments = malloc(sizeof(t_range) * (data.size + 1));
	ft_get_segments(&data, pile_sort, size, factor);
	ft_pile_clear(pile_sort);
	return (data);
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
		if (ft_is_crescent(piles.a))
			return (0);
		data = ft_get_pile_data(piles.a);
		sort_list = ft_sort_pile(&piles, data);
		free(data.segments);
		ft_print_sort_list(sort_list);
		ft_clear_sort_list(sort_list);
		ft_clear_stacks(piles);
	}
	return (0);
}