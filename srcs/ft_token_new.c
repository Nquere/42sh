/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:46:04 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 15:46:07 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_token		*ft_token_new(char *content, t_type type)
{
	t_token		*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new)
	{
		new->type = type;
		new->content = ft_strdup(content);
	}
	else
		ft_error("malloc ft_token_new() failed", NULL);
	return (new);
}
