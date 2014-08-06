/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcroot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 22:21:02 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:30:34 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <ldc.h>

static t_ldc	*findroot(t_ldc *list)
{
	if (list->content == NULL)
		return (list);
	return (findroot(list->next));
}

void			ft_ldcroot(t_ldc **list)
{
	if ((*list)->content == NULL)
		return ;
	else if ((*list)->next->content == NULL)
		*list = (*list)->next;
	else if ((*list)->previous->content == NULL)
		*list = (*list)->previous;
	else
		*list = findroot(*list);
}
