/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/17 18:32:41 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/19 04:50:51 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_listnew(void *content);
void				ft_listaddtail(t_list **list, void *content);
void				ft_listaddhead(t_list **list, void *content);
void				ft_listdestroy(t_list **list, void(*del)());
void				ft_listput(t_list *list, void(*aff)(), char *sep);
unsigned int		ft_listsize(t_list *list);

#endif
