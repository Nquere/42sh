/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:46:27 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 17:53:10 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		ft_token_del(t_token **token)
{
	char		*test;

	if (!token)
		return (1);
	if (*token)
		test = (*token)->content;
	ft_strdel(&test);
	free(*token);
	*token = NULL;
	return (0);
}
