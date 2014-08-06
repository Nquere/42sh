/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlprefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 04:01:51 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/27 17:34:49 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <avl.h>

static void		ft_avlprefixrec(t_avl *tree)
{
	if (!tree)
		return ;
	ft_putstr((char *)tree->content);
	ft_putchar(' ');
	ft_avlprefixrec(tree->left);
	ft_avlprefixrec(tree->right);
}

void			ft_avlprefix(t_avl *tree)
{
	ft_avlprefixrec(tree);
	ft_putchar('\n');
}
