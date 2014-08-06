/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlinfix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 01:02:26 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:08:04 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <avl.h>
#include <libft.h>

static void		ft_avlinfixrec(t_avl *tree)
{
	if (tree == NULL)
		return ;
	ft_avlinfixrec(tree->left);
	ft_putstr((char *)tree->content);
	ft_putchar(' ');
	ft_avlinfixrec(tree->right);
}

void			ft_avlinfix(t_avl *tree)
{
	ft_avlinfixrec(tree);
	ft_putchar('\n');
}
