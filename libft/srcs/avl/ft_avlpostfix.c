/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlpostfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 04:01:01 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:10:50 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <avl.h>

static void		ft_avlpostfixrec(t_avl *tree)
{
	if (tree == NULL)
		return ;
	ft_avlpostfixrec(tree->left);
	ft_avlpostfixrec(tree->right);
	ft_putstr((char *)tree->content);
	ft_putchar(' ');
}

void			ft_avlpostfix(t_avl *tree)
{
	ft_avlpostfixrec(tree);
	ft_putchar('\n');
}
