/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:45:26 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 18:02:41 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static void		tree_red(t_tree *ast, char *red, char **env)
{
	t_type		left;
	t_type		right;
	char		*cmd1;
	char		*cmd2;

	left = ft_token_get_type((ast->left)->content);
	right = ft_token_get_type((ast->right)->content);
	cmd1 = ft_token_get_str((ast->left)->content);
	cmd2 = ft_token_get_str((ast->right)->content);
	if ((left == COM || left == ARG) && (right == COM || right == ARG))
	{
		ft_redir(env, cmd1, red, cmd2);
		ft_treedestroy(&(ast->left), (void *)ft_token_del);
		ft_treedestroy(&(ast->right), (void *)ft_token_del);
	}
	else
		return ;
}

static void		tree_pipe(t_tree *ast, char **env)
{
	t_type		left;
	t_type		right;
	char		*cmd1;
	char		*cmd2;

	left = ft_token_get_type((ast->left)->content);
	right = ft_token_get_type((ast->right)->content);
	cmd1 = ft_token_get_str((ast->left)->content);
	cmd2 = ft_token_get_str((ast->right)->content);
	if ((left == COM || left == ARG) && (right == COM || right == ARG))
	{
		ft_pipe(env, cmd1, cmd2);
		ft_treedestroy(&(ast->left), (void *)ft_token_del);
		ft_treedestroy(&(ast->right), (void *)ft_token_del);
	}
	else
		return ;
}

static void		tree_exec(t_tree *ast, char **env, char *str)
{
	t_type		left;
	t_type		right;
	char		*cmd1;
	char		*cmd2;

	left = ft_token_get_type((ast->left)->content);
	right = ft_token_get_type((ast->right)->content);
	cmd1 = ft_token_get_str((ast->left)->content);
	cmd2 = ft_token_get_str((ast->right)->content);
	if ((left == COM || left == ARG) && (right == COM || right == ARG))
	{
		ft_add_cmd(env, cmd1, cmd2, str);
		ft_treedestroy(&(ast->left), (void *)ft_token_del);
		ft_treedestroy(&(ast->right), (void *)ft_token_del);
	}
	else
		return ;
}

void			burn_tree(t_tree *ast, char **env)
{
	char		*type;
	t_type		cmd;

	if (!ast)
		return ;
	type = ft_token_get_str(ast->content);
	cmd = ft_token_get_type(ast->content);
	if (cmd == COM || cmd == ARG)
		ft_execve(env, type);
	if (ft_strequ(type, "|"))
		tree_pipe(ast, env);
	if (ft_strequ(type, "<"))
		tree_red(ast, "<", env);
	if (ft_strequ(type, ">"))
		tree_red(ast, ">", env);
	if (ft_strequ(type, ">>"))
		tree_red(ast, ">>", env);
	if (ft_strequ(type, "&&"))
		tree_exec(ast, env, "&&");
	if (ft_strequ(type, "||"))
		tree_exec(ast, env, "||");
	burn_tree(ast->left, env);
	burn_tree(ast->right, env);
}
