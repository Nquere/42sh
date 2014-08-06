/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:55:01 by nquere            #+#    #+#             */
/*   Updated: 2014/06/23 17:55:23 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

void		test2(char *cmd, char **env)
{
	t_list		*list;
	t_tree		*ast;

	list = newlexer(cmd, env);
	ast = newparser(list);
	burn_tree(ast, env);
	ft_treedestroy(&ast, (void *)ft_token_del);
}
