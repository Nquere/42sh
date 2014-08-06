/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 02:15:58 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/14 17:05:54 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

static void		env_add(char ***env, char *content, int flag)
{
	char		**new;
	char		**old;
	size_t		size;
	size_t		i;

	old = *env;
	size = ft_tablen(old) + 2;
	new = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size - 2)
	{
		new[i] = ft_strdup(old[i]);
		i++;
	}
	if (!flag)
		new[i] = ft_strjoin(content, "=");
	else
		new[i] = content;
	new[i + 1] = NULL;
	ft_destroysplit(old);
	*env = new;
}

static int		check_args(char **args)
{
	char	**tmp;

	tmp = args;
	args++;
	while (*args)
	{
		if (ft_strchr(*args, '='))
		{
			ft_destroysplit(tmp);
			ft_putendl_fd("setenv: Syntax Error.", 2);
			return (1);
		}
		args++;
	}
	return (0);
}

static void		setenv_one(char ***env, char *cmd)
{
	char		*key;
	char		**tmp;
	size_t		i;

	key = ft_getenv(*env, cmd);
	if (!key)
		env_add(env, cmd, 0);
	else
	{
		tmp = *env;
		i = 0;
		while (tmp[i] && ft_strncmp(tmp[i], cmd, ft_strlen(cmd)))
			i++;
		free(tmp[i]);
		tmp[i] = ft_strjoin(cmd, "=");
		*env = tmp;
	}
	ft_strdel(&key);
}

static void		setenv_two(char ***env, char *key, char *value)
{
	char		*new;
	char		*search;
	char		**tmp;
	size_t		i;

	new = ft_strjoin(key, "=");
	search = ft_getenv(*env, key);
	if (!search)
		env_add(env, ft_strjoin(new, value), 1);
	else
	{
		tmp = *env;
		i = 0;
		while (tmp[i] && ft_strncmp(tmp[i], key, ft_strlen(key)))
			i++;
		free(tmp[i]);
		tmp[i] = ft_strjoin(new, value);
		*env = tmp;
		ft_strdel(&search);
	}
	ft_strdel(&new);
}

int				ft_setenv(char ***env, char *cmd)
{
	char		**arg;
	size_t		size;

	arg = ft_strsplit(cmd, ' ');
	size = ft_tablen(arg);
	if (check_args(arg))
		return (-1);
	if (size == 1)
		ft_puttab(*env);
	if (size == 2)
		setenv_one(env, arg[1]);
	if (size == 3)
		setenv_two(env, arg[1], arg[2]);
	ft_destroysplit(arg);
	if (size > 3)
		ft_putendl_fd("setenv: Too many arguments.", 2);
	return (1);
}
