/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 18:23:23 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/10 21:37:44 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

static char		*is_operator(char *str)
{
	if (ft_strstr(str, " < "))
		return ("<");
	if (ft_strstr(str, " > "))
		return (">");
	if (ft_strstr(str, " | "))
		return ("|");
	if (ft_strstr(str, " >> "))
		return (">>");
	if (ft_strstr(str, " << "))
	{
		ft_error("Operator not yet support.", NULL);
		return (NULL);
	}
	return (NULL);
}

static int		exec_op(char *op, char *cmd, char **env)
{
	char	**tab;
	int		ret;

	if (!(tab = ft_strsplit(cmd, ' ')))
		return (0);
	if (ft_tablen(tab) != 3)
	{
		ft_destroysplit(tab);
		return (ft_error("Format : <cmd|file> <operator> <cmd|file>", NULL));
	}
	if (ft_strequ(op, "|"))
	{
		ft_pipe(env, tab[0], tab[2]);
		ft_destroysplit(tab);
		return (1);
	}
	else
	{
		ret = ft_redir(env, tab[0], tab[1], tab[2]);
		ft_destroysplit(tab);
		return (ret);
	}
}

int				lexer(char *line, char **env)
{
	char	*op;

	if ((op = is_operator(line)))
		return (exec_op(op, line, env));
	ft_execve(env, line);
	return (0);
}
