/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 18:43:24 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 19:37:58 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <avl.h>

t_avl	*ft_avlinsert(t_avl *a, void *content)
{
	if (!a)
		return (ft_avlnew(content));
	if (*(char *)content < *(char *)a->content)
		a->left = ft_avlinsert(a->left, content);
	else if (*(char *)content > *(char *)a->content)
		a->right = ft_avlinsert(a->right, content);
	else
		a->content = ft_strdup(content);
	return (ft_avlbalancing(a));
}
