/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:40:37 by lucocozz          #+#    #+#             */
/*   Updated: 2021/03/08 18:46:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

t_sort_list	*ft_create_sort_list(int value, void (*ft)(t_stacks*))
{
	t_sort_list *sort;

	if ((sort = malloc(sizeof(t_sort_list) * 1)) == NULL)
		return (NULL);
	sort->value = value;
	sort->ft = ft;
	sort->next = NULL;
	return (sort);
}

void	ft_push_back_sort(t_sort_list **sort_list, int value,
void (*ft)(t_stacks*))
{
	t_sort_list	*tmp;

	tmp = *sort_list;
	if (!tmp)
		*sort_list = ft_create_sort_list(value, ft);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_sort_list(value, ft);
	}
}

void	ft_clear_sort_list(t_sort_list *sort_list)
{
	t_sort_list *prev;

	while (sort_list)
	{
		prev = sort_list;
		sort_list = sort_list->next;
		free(prev);
	}
}
