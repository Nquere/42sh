/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treesufix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 01:46:54 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/16 03:28:14 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tree.h>

static void		rec_treesufix(t_tree *a, void(*aff)(), char *sep)
{
	if (!a)
		return ;
	rec_treesufix(a->left, aff, sep);
	rec_treesufix(a->right, aff, sep);
	aff(a->content);
	if (sep)
		ft_putstr(sep);
}

void			ft_treesufix(t_tree *a, void(*aff)(), char *sep)
{
	rec_treesufix(a, aff, sep);
	ft_putchar('\n');
}
