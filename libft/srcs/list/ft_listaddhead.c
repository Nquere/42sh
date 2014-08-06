/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listaddhead.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 18:57:45 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:31:36 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	ft_listaddhead(t_list **list, void *content)
{
	t_list		*new;

	new = ft_listnew(content);
	if (!(*list))
		*list = new;
	else
	{
		new->next = *list;
		*list = new;
	}
}
