/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeputrev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 02:20:01 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/16 03:37:23 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tree.h>

static void		rec_treeputrev(t_tree *a, void(*aff)(), char *sep)
{
	if (!a)
		return ;
	rec_treeputrev(a->right, aff, sep);
	aff(a->content);
	if (sep)
		ft_putstr(sep);
	rec_treeputrev(a->left, aff, sep);
}

void			ft_treeputrev(t_tree *a, void(*aff)(), char *sep)
{
	rec_treeputrev(a, aff, sep);
}
