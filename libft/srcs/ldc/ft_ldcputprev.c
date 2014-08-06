/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcputprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 22:53:24 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:28:37 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ldc.h>

void	ft_ldcputprev(t_ldc *list, void(*aff)(), char *sep)
{
	if (!list)
	{
		ft_putendl(NULL);
		return ;
	}
	if (list->content == NULL)
		list = list->previous;
	while (list->content)
	{
		aff(list->content);
		if (list->previous->content)
			ft_putstr(sep);
		list = list->previous;
	}
	ft_putchar('\n');
}
