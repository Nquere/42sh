/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changedir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 03:36:15 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/14 17:06:20 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

static char		*cd_tild(char *arg, char **env)
{
	char		*home;
	char		*new;

	home = ft_getenv(env, "HOME=");
	new = ft_replace(arg, "~", home);
	ft_strdel(&home);
	return (new);
}

static char		*cd_path(char ***env, char **split)
{
	char		*buf;
	char		*tmp;
	char		*path;

	buf = ft_strnew(1000000);
	path = getcwd(buf, 1000000);
	tmp = ft_strjoin(path, "/");
	ft_strdel(&path);
	if (split[1])
	{
		if (ft_strequ(split[1], "-"))
			path = ft_getenv(*env, "OLDPWD=");
		else if (ft_strchr(split[1], '~'))
			path = cd_tild(split[1], *env);
		else
			path = ft_strjoin(tmp, split[1]);
	}
	else
		path = ft_getenv(*env, "HOME=");
	ft_strdel(&tmp);
	return (path);
}

static int		cd_error(char ***env, char *path, char **split)
{
	char	*tmp;

	tmp = ft_getenv(*env, "HOME=");
	if (!tmp)
		ft_error("cd : Can't change to home directory.", NULL);
	else if (ft_tablen(split) > 3)
		ft_error("cd: Too many arguments.", NULL);
	else if (access(path, F_OK) == -1)
		ft_error("cd: no such file or directory.", NULL);
	else if (access(path, R_OK) == -1)
		ft_error("cd: Permission denied.", NULL);
	ft_strdel(&tmp);
	ft_strdel(&path);
	ft_destroysplit(split);
	return (-1);
}

static int		cd_env(char ***env, char *path, char **split)
{
	char		*old;
	char		*pwd;
	char		*tmp;
	char		*buf;

	buf = ft_strnew(1000000);
	tmp = getcwd(buf, 1000000);
	old = ft_getenv(*env, "PWD=");
	pwd = ft_strjoin("setenv PWD ", tmp);
	ft_strdel(&tmp);
	ft_setenv(env, pwd);
	ft_strdel(&pwd);
	pwd = ft_strjoin("setenv OLDPWD ", old);
	ft_setenv(env, pwd);
	ft_strdel(&pwd);
	ft_strdel(&old);
	ft_strdel(&path);
	ft_destroysplit(split);
	return (1);
}

int				ft_changedir(char ***env, char *cmd)
{
	char	*path;
	char	**split;

	if (!cmd)
		return (-1);
	split = ft_strsplit(cmd, ' ');
	if (!split)
		return (-1);
	path = cd_path(env, split);
	if (chdir(path) == -1)
		return (cd_error(env, path, split));
	else
		return (cd_env(env, path, split));
}
