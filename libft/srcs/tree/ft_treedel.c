/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 23:58:26 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/16 00:56:06 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tree.h>
#include <stdlib.h>

void	ft_treedel(t_tree **a, void(*del)())
{
	if (!*a)
		return ;
	if ((*a)->left == NULL && (*a)->right == NULL)
	{
		del(&((*a)->content));
		free(*a);
		*a = NULL;
	}
}
