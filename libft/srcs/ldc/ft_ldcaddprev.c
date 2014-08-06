/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcaddprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 22:28:12 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:21:41 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ldc.h>

void	ft_ldcaddprev(t_ldc **list, void *content)
{
	t_ldc	*new;

	if (!content && *list)
		return ;
	new = ft_ldcnew(content);
	if (!*list)
		*list = ft_ldcnew(NULL);
	if (new && content && *list)
	{
		new->previous = (*list)->previous;
		new->next = (*list);
		(*list)->previous->next = new;
		(*list)->previous = new;
	}
}
