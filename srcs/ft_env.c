/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 22:23:47 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/14 17:05:29 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

static int		is_env(char c)
{
	if (c == 'i')
		return (1);
	return (0);
}

static char		**create_env(char ***env, t_list *list, char *opt)
{
	char		**new_env;

	if (!env || !list)
		return (NULL);
	if (ft_strchr(opt, 'i'))
	{
		if (ft_strchr((char *)(list->content), '='))
		{
			if (!(new_env = (char **)malloc(sizeof(char *) * 2)))
				return (NULL);
			new_env[0] = ft_strdup((char *)(list->content));
			new_env[1] = NULL;
		}
		else
		{
			if (!(new_env = (char **)malloc(sizeof(char *) * 1)))
				return (NULL);
			new_env[0] = NULL;
		}
	}
	else
		new_env = ft_sstrdup(*env);
	return (new_env);
}

static void		exec_env(t_list *name, char **new_env)
{
	char		*cmd;

	while (name)
	{
		cmd = ft_listtochar(name, " ");
		ft_execve(new_env, cmd);
		ft_strdel(&cmd);
		name = name->next;
	}
	ft_destroysplit(new_env);
}

static void		new_env(char ***env, t_list *name, char *opt)
{
	char		**new_env;
	char		**split;
	char		*tmp;
	char		*set_env;

	if (!(new_env = create_env(env, name, opt)))
		return ;
	while (name)
	{
		if (ft_strchr((char *)(name->content), '='))
		{
			tmp = ft_strjoin("setenv=", (char *)(name->content));
			split = ft_strsplit(tmp, '=');
			set_env = ft_implode(split, " ");
			ft_setenv(&new_env, set_env);
			ft_strdel(&set_env);
			ft_strdel(&tmp);
			ft_destroysplit(split);
		}
		else
			break ;
		name = name->next;
	}
	exec_env(name, new_env);
}

int				ft_env(char ***env, char *cmd)
{
	char		**arg;
	char		*opt;
	t_list		*name;

	if (!env || !cmd)
		return (1);
	arg = ft_strsplit(cmd, ' ');
	name = NULL;
	opt = NULL;
	if (ft_parse_option(arg, &opt, &name, &is_env))
	{
		if (!opt && !name)
			ft_puttab(*env);
		new_env(env, name, opt);
		ft_strdel(&opt);
		ft_listdestroy(&name, ft_strdel);
	}
	ft_destroysplit(arg);
	return (1);
}
