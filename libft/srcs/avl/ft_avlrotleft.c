/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlrotleft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 04:02:34 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/27 17:35:18 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avl.h>

t_avl		*ft_avlrotleft(t_avl *a)
{
	t_avl		*b;

	b = a->right;
	a->right = b->left;
	b->left = a;
	ft_avlsetheight(b->left);
	ft_avlsetheight(b);
	return (b);
}
