/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlrotright.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 04:01:14 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/27 17:35:49 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avl.h>

t_avl		*ft_avlrotright(t_avl *a)
{
	t_avl	*b;

	b = a->left;
	a->left = b->right;
	b->right = a;
	ft_avlsetheight(b->right);
	ft_avlsetheight(b);
	return (b);
}
