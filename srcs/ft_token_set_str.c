/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_set_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:46:55 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 15:52:45 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		ft_token_set_str(t_token *token, char *str)
{
	if (!token)
		return (1);
	ft_strdel(&(token->content));
	token->content = ft_strdup(str);
	return (0);
}
