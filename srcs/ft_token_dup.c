/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:53:12 by nquere            #+#    #+#             */
/*   Updated: 2014/06/23 17:55:30 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_token		*ft_token_dup(t_token *token)
{
	if (!token)
		return (token);
	return (ft_token_new(token->content, token->type));
}
