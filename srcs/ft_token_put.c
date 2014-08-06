/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:46:15 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 17:53:48 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static void		put_type(t_type type)
{
	if (type == COM)
		ft_putstr("COM");
	else if (type == ARG)
		ft_putstr("ARG");
	else if (type == OR)
		ft_putstr("OR");
	else if (type == AND)
		ft_putstr("AND");
	else if (type == PIPE)
		ft_putstr("PIPE");
	else if (type == RED)
		ft_putstr("RED");
	else
		ft_putstr("UNKNOW");
}

int				ft_token_put(t_token *token)
{
	if (!token)
		return (1);
	ft_putstr("[");
	put_type(token->type);
	ft_putstr("]->");
	ft_putendl(token->content);
	return (0);
}
