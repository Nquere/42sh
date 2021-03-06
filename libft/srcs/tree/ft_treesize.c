/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 22:32:46 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/18 22:46:38 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tree.h>
#include <stdlib.h>

int		rec_treesize(t_tree *a)
{
	if (a == NULL)
		return (0);
	else
		return (1 + rec_treesize(a->left) + rec_treesize(a->right));
}

int		ft_treesize(t_tree *a)
{
	return (rec_treesize(a));
}
