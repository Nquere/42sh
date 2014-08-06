/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeprefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 01:55:53 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/16 03:28:37 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <libft.h>

static void		rec_treeprefix(t_tree *a, void(*aff)(), char *sep)
{
	if (!a)
		return ;
	aff(a->content);
	if (sep)
		ft_putstr(sep);
	rec_treeprefix(a->left, aff, sep);
	rec_treeprefix(a->right, aff, sep);
}

void			ft_treeprefix(t_tree *a, void(*aff)(), char *sep)
{
	rec_treeprefix(a, aff, sep);
	ft_putchar('\n');
}
