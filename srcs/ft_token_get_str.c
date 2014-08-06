/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_get_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:47:22 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 15:47:26 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#include <string.h>

char		*ft_token_get_str(t_token *token)
{
	if (!token)
		return (NULL);
	return (token->content);
}
