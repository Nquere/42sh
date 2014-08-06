/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcputnext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 22:47:44 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:29:44 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ldc.h>

void	ft_ldcputnext(t_ldc *list, void(*aff)(), char *sep)
{
	if (!list)
	{
		ft_putendl(NULL);
		return ;
	}
	if (list->content == NULL)
		list = list->next;
	while (list->content)
	{
		aff(list->content);
		if (list->next->content)
			ft_putstr(sep);
		list = list->next;
	}
	ft_putchar('\n');
}
