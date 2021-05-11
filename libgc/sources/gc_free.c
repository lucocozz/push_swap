/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/11 17:36:27 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_free(void *garbage_to_free)
{
	t_garbage_lst	**garbage_lst;
	t_garbage_lst	*current;
	t_garbage_lst	*previous;

	garbage_lst = get_garbage_lst();
	current = *garbage_lst;
	previous = NULL;
	while (current->ptr != garbage_to_free)
	{
		previous = current;
		current = current->next;
	}
	if (previous == NULL)
		*garbage_lst = current->next;
	else
		previous->next = current->next;
	gc_memdel((void **)&current->ptr);
	gc_memdel((void **)&current);
}
