/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 22:04:52 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/27 17:45:56 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LDC_H
# define LDC_H

typedef struct			s_ldc
{
	void				*content;
	struct s_ldc		*previous;
	struct s_ldc		*next;
}						t_ldc;

t_ldc					*ft_ldcnew(void *content);
void					ft_ldcroot(t_ldc **list);
void					ft_ldcaddprev(t_ldc **root, void *content);
void					ft_ldcaddnext(t_ldc **root, void *content);
void					ft_ldcputnext(t_ldc *root, void(*aff)(), char *sep);
void					ft_ldcputprev(t_ldc *root, void(*aff)(), char *sep);
void					ft_ldcdel(t_ldc **root, void(*del)());
void					ft_ldcdestroy(t_ldc **root, void(*del)());
void					ft_ldcput(t_ldc *list, void(*aff)());
void					ft_ldcnext(t_ldc **list);
void					ft_ldcprev(t_ldc **list);

#endif
