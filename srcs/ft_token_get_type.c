/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_get_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:47:10 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 15:47:13 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

t_type		ft_token_get_type(t_token *token)
{
	if (!token)
		return (ERROR);
	return (token->type);
}
