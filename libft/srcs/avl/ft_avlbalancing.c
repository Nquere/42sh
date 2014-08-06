/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlbalancing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 04:00:34 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:06:26 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avl.h>

t_avl	*ft_avlbalancing(t_avl *a)
{
	ft_avlsetheight(a);
	if (ft_avlheight(a->left) - ft_avlheight(a->right) == 2)
	{
		if (ft_avlheight(a->left->left) < ft_avlheight(a->left->right))
			a->left = ft_avlrotleft(a->left);
		return (ft_avlrotright(a));
	}
	if (ft_avlheight(a->left) - ft_avlheight(a->right) == -2)
	{
		if (ft_avlheight(a->right->right) < ft_avlheight(a->right->left))
			a->right = ft_avlrotright(a->right);
		return (ft_avlrotleft(a));
	}
	return (a);
}
