/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeinfix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 19:48:52 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/16 03:27:51 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tree.h>

static void		rec_treeinfix(t_tree *a, void(*aff)(), char *sep)
{
	if (!a)
		return ;
	rec_treeinfix(a->left, aff, sep);
	aff(a->content);
	if (sep)
		ft_putstr(sep);
	rec_treeinfix(a->right, aff, sep);
}

void			ft_treeinfix(t_tree *a, void(*aff)(), char *sep)
{
	rec_treeinfix(a, aff, sep);
	ft_putchar('\n');
}
