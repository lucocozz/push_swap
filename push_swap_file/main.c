/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:23:55 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/08 19:36:42 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_stacks	piles;

	if (argc > 2)
	{
		piles.a = ft_parsing(argc - 1, &argv[1]);
		ft_pile_clear(piles.a);
	}
	return (0);
}