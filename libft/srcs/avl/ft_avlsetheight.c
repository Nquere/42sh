/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlsetheight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:06:07 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/27 17:37:40 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avl.h>

void		ft_avlsetheight(t_avl *tree)
{
	int		hl;
	int		hr;

	hl = ft_avlheight(tree->left);
	hr = ft_avlheight(tree->right);
	tree->height = 1 + ((hl > hr) ? hl : hr);
}
