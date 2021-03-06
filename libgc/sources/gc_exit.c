/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:01:22 by rotrojan          #+#    #+#             */
/*   Updated: 2021/05/11 17:36:16 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgc.h"

void	gc_exit(int status, char *message)
{
	gc_free_all();
	if (status == EXIT_SUCCESS && message != NULL)
		gc_putstr_fd(STDOUT_FILENO, message);
	else if (status == EXIT_FAILURE)
		gc_putstr_fd(STDERR_FILENO, message);
	exit(status);
}
