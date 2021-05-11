/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 16:05:23 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/11 17:36:55 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGC_H
# define LIBGC_H

# include <stdlib.h>
# include <unistd.h>

typedef struct				s_garbage_lst
{
	void					*ptr;
	struct s_garbage_lst	*next;
}							t_garbage_lst;

void						*gc_alloc(size_t size);
void						gc_free(void *garbage_to_free);
void						gc_free_all(void);
void						gc_exit(int status, char *message);
t_garbage_lst				**get_garbage_lst(void);

void						gc_memdel(void **ap);
void						gc_bzero(void *s, size_t n);
void						gc_putstr_fd(int fd, char const *str);

#endif
