/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:26:25 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/09 00:50:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int			ft_init_sort_list(t_sort_list *sort_list, char *sort)
{
	if (!ft_strcmp(sort, "sa"))
		ft_push_back_sort(&sort_list, SA, &ft_sa);
	else if (!ft_strcmp(sort, "sb"))
		ft_push_back_sort(&sort_list, SB, &ft_sb);
	else if (!ft_strcmp(sort, "ss"))
		ft_push_back_sort(&sort_list, SS, &ft_ss);
	else if (!ft_strcmp(sort, "pa"))
		ft_push_back_sort(&sort_list, PA, &ft_pa);
	else if (!ft_strcmp(sort, "pb"))
		ft_push_back_sort(&sort_list, PB, &ft_pb);
	else if (!ft_strcmp(sort, "ra"))
		ft_push_back_sort(&sort_list, RA, &ft_ra);
	else if (!ft_strcmp(sort, "rb"))
		ft_push_back_sort(&sort_list, RB, &ft_rb);
	else if (!ft_strcmp(sort, "rr"))
		ft_push_back_sort(&sort_list, RR, &ft_rr);
	else if (!ft_strcmp(sort, "rra"))
		ft_push_back_sort(&sort_list, RRA, &ft_rra);
	else if (!ft_strcmp(sort, "rrb"))
		ft_push_back_sort(&sort_list, RRB, &ft_rrb);
	else if (!ft_strcmp(sort, "rrr"))
		ft_push_back_sort(&sort_list, RRR, &ft_rrr);
	else
		return (0);
	return (1);
}

static t_sort_list	*ft_get_sort_list(void)
{
	int			ret;
	char		*line;
	t_sort_list	*sort_list;

	sort_list = NULL;
	while ((ret = get_next_line(&line)) == 1)
	{
		if (!ft_init_sort_list(sort_list, line))
		{
			ft_clear_sort_list(sort_list);
			ret = -1;
		}
		free(line);
	}
	return (ret == -1 ? NULL : sort_list);
}

int					main(int argc, char **argv)
{
	t_stacks	piles;
	t_sort_list	*sort_list;

	piles.b = NULL;
	if (argc > 2)
	{
		piles.a = ft_parsing(argc - 1, &argv[1]);
		if (!(sort_list = ft_get_sort_list()))
			ft_exit_error(piles);
		ft_clear_sort_list(sort_list);
		ft_pile_clear(piles.a);
		ft_pile_clear(piles.b);
	}
	return (0);
}