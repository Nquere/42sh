/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 18:29:04 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/19 04:50:09 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

unsigned int		ft_listsize(t_list *list)
{
	unsigned int	k;

	k = 0;
	if (!list)
		return (k);
	while (list)
	{
		k++;
		list = list->next;
	}
	return (k);
}
