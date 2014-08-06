/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listaddtail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 18:50:51 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:31:21 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void		ft_listaddtail(t_list **list, void *content)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_listnew(content);
	if (!(*list))
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
