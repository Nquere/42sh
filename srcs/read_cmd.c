/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:54:14 by nquere            #+#    #+#             */
/*   Updated: 2014/06/23 17:56:11 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static char		*concat_cmd(t_list *tmp, t_list **list)
{
	char		*str;
	char		*old;
	char		*new;
	char		*tmp2;
	t_type		type;

	str = ft_strdup(ft_token_get_str(tmp->content));
	tmp = tmp->next;
	if (!tmp)
		return (str);
	type = ft_token_get_type(tmp->content);
	while (tmp && type == ARG)
	{
		*list = tmp;
		tmp2 = ft_token_get_str(tmp->content);
		old = str;
		new = ft_strjoin(" ", tmp2);
		str = ft_strjoin(old, new);
		ft_strdel(&new);
		ft_strdel(&old);
		tmp = tmp->next;
		if (tmp)
			type = ft_token_get_type(tmp->content);
	}
	return (str);
}

t_token			*read_cmd(t_list **list)
{
	t_token		*token;
	char		*str;

	str = concat_cmd(*list, list);
	token = ft_token_new(str, COM);
	ft_strdel(&str);
	return (token);
}
