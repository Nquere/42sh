/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 18:58:52 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/27 17:34:10 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <avl.h>

t_avl		*ft_avlnew(void *content)
{
	t_avl	*new;

	new = (t_avl *)malloc(sizeof(t_avl));
	if (new)
	{
		new->right = NULL;
		new->left = NULL;
		new->content = ft_strdup(content);
		ft_avlsetheight(new);
	}
	return (new);
}
