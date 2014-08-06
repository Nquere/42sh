/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_exp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:54:22 by nquere            #+#    #+#             */
/*   Updated: 2014/06/23 17:57:11 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static int		omg_ast(t_tree **ast, t_tree *new)
{
	t_type		type;

	type = ft_token_get_type((*ast)->content);
	if (!(*ast)->left && !(*ast)->right)
		*ast = new;
	else if (type == AND || type == OR)
	{
		new->left = (*ast)->right;
		(*ast)->right = new;
	}
	else
		*ast = new;
	return (1);
}

static t_tree	*new_tree(t_list **list, t_tree *ast)
{
	t_list		*operateur;
	t_list		*commande;
	t_tree		*new;
	t_type		test;
	t_token		*cmd;

	operateur = *list;
	commande = (*list)->next;
	test = ft_token_get_type(operateur->content);
	if (test == COM || test == ARG || test == ERROR)
		return (NULL);
	test = ft_token_get_type(commande->content);
	if (!(test == COM || test == ARG))
		return (NULL);
	*list = (*list)->next;
	if (test == COM)
		cmd = read_cmd(list);
	else
		cmd = ft_token_dup((*list)->content);
	new = ft_treenew(ft_token_dup(operateur->content));
	new->right = ft_treenew(cmd);
	new->left = ast;
	return (new);
}

static int		add_ast(t_tree **ast, t_list **list)
{
	t_type		type;
	t_tree		*new;

	if (ft_listsize(*list) < 2)
		return (2);
	new = new_tree(list, *ast);
	if (!new)
		return (2);
	if (*list)
		*list = (*list)->next;
	type = ft_token_get_type(new->content);
	if (type == OR || type == AND)
		*ast = new;
	else
		omg_ast(ast, new);
	return (0);
}

static int		create_ast(t_tree **ast, t_list **list)
{
	t_list		*tmp;
	t_type		type;
	t_token		*token;

	tmp = *list;
	type = ft_token_get_type(tmp->content);
	if (type == COM || type == ARG)
	{
		if (type == COM)
			token = read_cmd(list);
		else
			token = ft_token_dup(tmp->content);
		*ast = ft_treenew(token);
		if (*list)
			*list = (*list)->next;
		return (0);
	}
	else
		return (2);
}

int				rules_exp(t_list **list, t_tree **ast)
{
	if (!list || !ast)
		return (2);
	if (!*list)
		return (1);
	if (!*ast)
		return (create_ast(ast, list));
	else
		return (add_ast(ast, list));
}
