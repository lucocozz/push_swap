/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:33:16 by lucocozz          #+#    #+#             */
/*   Updated: 2021/05/19 16:29:04 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit_error(t_stacks piles)
{
	ft_clear_stacks(piles);
	gc_exit(EXIT_FAILURE, "Error\n");
}

t_pile	*ft_parsing(int size, char **numbers)
{
	int			i;
	long long	value;
	t_pile		*a;

	i = 0;
	a = NULL;
	while (i < size)
	{
		if (!ft_isnumber(numbers[i]))
			ft_exit_error((t_stacks){a, NULL});
		value = ft_atoll(numbers[i]);
		if (!(value >= INT_MIN && value <= INT_MAX))
			ft_exit_error((t_stacks){a, NULL});
		if (!ft_pile_push_back_if_not(&a, (int)value))
			ft_exit_error((t_stacks){a, NULL});
		i++;
	}
	return (a);
}
