/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:23:55 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/28 20:15:03 by lucocozz         ###   ########.fr       */
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
	data.min = pile_sort->value;
	data.max = pile_sort->prev->value;
	size = ft_pile_size(pile_sort);
	tmp_sort = pile_sort;
	while (i++ < size / 2)
		tmp_sort = tmp_sort->next;
	data.mediane = tmp_sort->value;
	ft_pile_clear(pile_sort);
	return (data);
}

int					main(int argc, char **argv)
{
	t_stacks	piles;
	t_sort_list	*sort_list;

	piles.b = NULL;
	sort_list = NULL;
	if (argc > 2)
	{
		piles.a = ft_parsing(argc - 1, &argv[1]);
		sort_list = ft_insert_sort(&piles, ft_get_pile_data(piles.a));
		while (piles.b)
			ft_push_back_sort(&sort_list, ft_pa(&piles), NULL);
		ft_print_sort_list(sort_list);
		ft_pile_print(piles.a);
		ft_clear_sort_list(sort_list);
		ft_clear_stacks(piles);
	}
	return (0);
}
