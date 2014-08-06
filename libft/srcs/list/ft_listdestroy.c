/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdestroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:00:51 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:32:03 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <list.h>

static void		destroy(t_list *list, void(*del)())
{
	if (!list)
		return ;
	del(&(list->content));
	destroy(list->next, del);
	free(list);
}

void			ft_listdestroy(t_list **list, void(*del)())
{
	destroy(*list, del);
	*list = NULL;
}
