/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 22:16:47 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:28:02 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <ldc.h>

t_ldc	*ft_ldcnew(void *content)
{
	t_ldc		*new;

	new = (t_ldc *)malloc(sizeof(t_ldc));
	if (new)
	{
		new->content = content;
		new->next = new;
		new->previous = new;
	}
	return (new);
}
