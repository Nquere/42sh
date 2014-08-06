/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 19:03:45 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:33:37 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <list.h>

void	ft_listput(t_list *list, void(*aff)(), char *sep)
{
	if (!list)
		return ;
	aff(list->content);
	if (list->next)
	{
		if (sep)
			ft_putstr(sep);
	}
	else
		ft_putchar('\n');
	ft_listput(list->next, aff, sep);
}
