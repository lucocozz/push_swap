/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:23:55 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/30 16:38:36 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_get_segments(t_pile_data *data, t_pile *pile_sort, int size,
	int factor)
{
	t_count	c;
	t_pile	*tmp_sort;

	c.i = 0;
	c.j = 0;
	c.k = 0;
	tmp_sort = pile_sort;
	data->segments[c.i].min = tmp_sort->value;
	while (c.k++ <= size - 3)
	{
		if (c.j == factor && size >= factor / 2 - 1)
		{
			data->segments[c.i].max = tmp_sort->prev->value;
			data->segments[c.i].size = c.j;
			data->segments[++c.i].min = tmp_sort->value;
			c.j = 0;
		}
		tmp_sort = tmp_sort->next;
		c.j++;
	}
	data->segments[c.i].size = c.j;
	data->segments[c.i].max = tmp_sort->prev->value;
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
	if (size < 250)
		factor = 15;
	else
		factor = 35;
	if (size >= factor)
	{
		data.size = (size / factor);
		if (size % factor)
			data.size++;
	}
	else
		data.size = 1;
	data.segments = gc_alloc(sizeof(t_range) * (data.size + 1));
	ft_get_segments(&data, pile_sort, size, factor);
	ft_pile_clear(pile_sort);
	return (data);
}

int	main(int argc, char **argv)
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
		{
			ft_clear_stacks(piles);
			gc_exit(EXIT_SUCCESS, NULL);
		}
		data = ft_get_pile_data(piles.a);
		sort_list = ft_sort_pile(&piles, data);
		gc_free(data.segments);
		ft_print_sort_list(sort_list);
		ft_clear_sort_list(sort_list);
		ft_clear_stacks(piles);
	}
	gc_exit(EXIT_SUCCESS, NULL);
	return (0);
}
