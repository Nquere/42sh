/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listtochar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 00:21:41 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/14 17:06:34 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

char		*ft_listtochar(t_list *list, char *sep)
{
	char	*new;
	char	*old;
	char	*tmp;

	if (!list)
		return (NULL);
	new = ft_strjoin((char *)(list->content), sep);
	list = list->next;
	while (list)
	{
		old = new;
		tmp = ft_strjoin((char *)(list->content), sep);
		new = ft_strjoin(old, tmp);
		ft_strdel(&old);
		ft_strdel(&tmp);
		list = list->next;
	}
	return (new);
}
