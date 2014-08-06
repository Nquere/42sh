/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcaddnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 22:43:55 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:21:56 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ldc.h>

void	ft_ldcaddnext(t_ldc **list, void *content)
{
	t_ldc	*new;

	if (!content && *list)
		return ;
	new = ft_ldcnew(content);
	if (!*list)
		*list = ft_ldcnew(NULL);
	if (new && content && *list)
	{
		new->previous = *list;
		new->next = (*list)->next;
		(*list)->next->previous = new;
		(*list)->next = new;
	}
}
