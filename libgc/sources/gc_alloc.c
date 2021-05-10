/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:32:29 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/10 21:33:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	*gc_alloc(size_t size)
{
	t_garbage_lst	*tmp;
	t_garbage_lst	*new;
	t_garbage_lst	**garbage_lst;

	new = NULL;
	garbage_lst = get_garbage_lst();
	tmp = *garbage_lst;
	new = malloc(sizeof(t_garbage_lst));
	if (new == NULL)
		gc_exit(EXIT_FAILURE, "gc_alloc(): failed to allocate memory.\n");
	new->ptr = malloc(size);
	if (new->ptr == NULL)
		gc_exit(EXIT_FAILURE, "gc_alloc(): failed to allocate memory.\n");
	new->next = tmp;
	*garbage_lst = new;
	return (new->ptr);
}
