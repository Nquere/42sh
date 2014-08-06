/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 12:55:23 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 18:01:45 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unix.h>
#include <libft.h>

static char		**get_path(char **env)
{
	char	**path;
	char	*cmd;
	int		i;
	char	*test;

	if (!env)
		return (NULL);
	if (!(test = ft_getenv(env, "PATH=")))
		return (NULL);
	if (!(path = ft_strsplit(test, ':')))
		return (NULL);
	i = 0;
	while (path[i])
	{
		cmd = ft_strjoin(path[i], "/");
		ft_strdel(&path[i]);
		path[i++] = cmd;
	}
	ft_strdel(&test);
	return (path);
}

static void		exec_file(char **env, char **arg)
{
	char		*tmp;
	char		*buf;
	char		*name;
	char		*file;

	buf = ft_strnew(1000000);
	tmp = getcwd(buf, 1000000);
	buf = ft_strjoin(tmp, "/");
	file = ft_strchr(arg[0], '/');
	name = ft_strjoin(buf, ++file);
	execve(name, arg, env);
	ft_test_file(ft_strrchr(name, '/') + 1);
	ft_strdel(&buf);
	ft_strdel(&name);
	ft_strdel(&tmp);
	_exit(45);
}

static void		exec_cmd(char **path, char **env, char **arg)
{
	char	*cmd;

	if (path)
	{
		while (*path)
		{
			cmd = ft_strjoin(*path++, *arg);
			execve(cmd, arg, env);
			ft_strdel(&cmd);
		}
	}
	ft_error(arg[0], ": command not found.");
	_exit(42);
}

static void		ft_son(char **arg, char **env, char **path, char *str)
{
	execve(arg[0], arg, env);
	if (ft_strchr(str, '/'))
		exec_file(env, arg);
	else
		exec_cmd(path, env, arg);
}

int				ft_execve(char **env, char *str)
{
	char	**path;
	char	**arg;
	int		pid;
	int		ret;

	ret = 0;
	if (!str)
		return (1);
	path = get_path(env);
	arg = ft_strsplit(str, ' ');
	if ((pid = fork()) == -1)
		ft_error("fork failed : ", str);
	if (pid == 0)
		ft_son(arg, env, path, str);
	else
	{
		waitpid(pid, &ret, 0);
		ft_destroysplit(path);
		ft_destroysplit(arg);
	}
	return (ret);
}
