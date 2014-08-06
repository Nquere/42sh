/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:54:04 by nquere            #+#    #+#             */
/*   Updated: 2014/06/23 17:54:12 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static int	axiome(t_list *list, t_tree **ast)
{
	if (rules_exp(&list, ast))
		return (ft_error("Parsing syntax error", NULL));
	while (rules_exp(&list, ast) == 0)
		;
	return (0);
}

t_tree		*newparser(t_list *list)
{
	t_tree		*ast;
	t_list		*tmp;

	ast = NULL;
	if (!list)
		return (ast);
	tmp = list;
	axiome(list, &ast);
	ft_listdestroy(&tmp, (void*)ft_token_del);
	return (ast);
}
