/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 23:02:18 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/27 17:40:14 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ldc.h>

void	ft_ldcdel(t_ldc **list, void(*del)())
{
	t_ldc	*tmp;

	if (!*list)
		return ;
	if (!(*list)->content)
		return ;
	tmp = (*list)->next;
	(*list)->previous->next = (*list)->next;
	(*list)->next->previous = (*list)->previous;
	(*list)->previous = NULL;
	(*list)->next = NULL;
	if ((*list)->content)
		del(&((*list)->content));
	free(*list);
	*list = tmp;
}
