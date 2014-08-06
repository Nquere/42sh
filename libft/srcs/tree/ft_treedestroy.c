/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedestroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 23:40:55 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/16 00:54:40 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <tree.h>

void	ft_treedestroy(t_tree **a, void(*del)())
{
	if (*a == NULL)
		return ;
	ft_treedestroy(&((*a)->left), del);
	ft_treedestroy(&((*a)->right), del);
	ft_treedel(a, del);
}
