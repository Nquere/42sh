/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_set_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:46:41 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 15:46:44 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		ft_token_set_type(t_token *token, t_type type)
{
	if (!token)
		return (1);
	token->type = type;
	return (0);
}
