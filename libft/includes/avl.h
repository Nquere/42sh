/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 01:29:15 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/27 17:43:13 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_H
# define AVL_H

typedef struct			s_avl
{
	void				*content;
	struct s_avl		*left;
	struct s_avl		*right;
	int					height;
}						t_avl;

t_avl					*ft_avlnew(void *content);
int						ft_avlheight(t_avl *tree);
void					ft_avlsetheight(t_avl *tree);
t_avl					*ft_avlrotleft(t_avl *tree);
t_avl					*ft_avlrotright(t_avl *tree);
t_avl					*ft_avlbalancing(t_avl *tree);
t_avl					*ft_avlinsert(t_avl *tree, void *content);
void					ft_avlinfix(t_avl *tree);
void					ft_avlprefix(t_avl *tree);
void					ft_avlpostfix(t_avl *tree);

#endif
