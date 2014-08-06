/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcdestroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 23:08:53 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/27 17:40:49 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ldc.h>

void	ft_ldcdestroy(t_ldc **list, void(*del)())
{
	if (!*list)
		return ;
	ft_ldcroot(list);
	*list = (*list)->next;
	while ((*list)->content)
		ft_ldcdel(list, del);
	free(*list);
	(*list)->previous = NULL;
	(*list)->next = NULL;
	*list = NULL;
}
