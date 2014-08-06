/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 12:59:44 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/18 22:23:34 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unix.h>
#include <libft.h>
#include <fcntl.h>

static int		redir_file(char *file, char c)
{
	if (ft_file_exist(file))
	{
		if ((access(file, W_OK) == 0) && (c == 'w'))
			return (1);
		if (access(file, R_OK) == 0 && (c == 'r'))
			return (1);
		else
			return (ft_error(file, ": Permission denied."));
	}
	if (c == 'r')
		return (ft_error(file, ": no such file or directory."));
	return (1);
}

static int		is_operator(char *op, char *file, int flag)
{
	if (!flag)
	{
		if (ft_strequ(op, "<"))
			return (1);
		if (ft_strequ(op, "<<"))
			return (1);
		if (ft_strequ(op, ">>"))
			return (2);
		if (ft_strequ(op, ">"))
			return (2);
		return (0);
	}
	else
	{
		if (ft_strequ(op, ">"))
			return (open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644));
		if (ft_strequ(op, ">>"))
			return (open(file, O_CREAT | O_WRONLY | O_APPEND, 0644));
		if (ft_strequ(op, "<"))
			return (open(file, O_RDONLY));
		return (0);
	}
}

static int		do_redir(char **env, char *file, char *cmd, char *op)
{
	int			fd;
	int			pid;

	if ((fd = is_operator(op, file, 1)) < 0)
		return (ft_error("open() failed.", NULL));
	if ((pid = fork()) == -1)
	{
		close(fd);
		return (ft_error("fork() failed.", NULL));
	}
	if (pid == 0)
	{
		(ft_strequ(op, "<")) ? dup2(fd, 0) : dup2(fd, 1);
		ft_execve(env, cmd);
		_exit(0);
	}
	else
	{
		close(fd);
		wait(&pid);
		return (1);
	}
}

int				ft_redir(char **env, char *cmd1, char *op, char *cmd2)
{
	char		*file;
	char		*cmd;
	int			ret;

	if (!env || !(ret = is_operator(op, NULL, 0)))
		return (0);
	file = cmd2;
	cmd = cmd1;
	if (ret == 1)
	{
		if (!redir_file(file, 'r'))
			return (0);
	}
	else
	{
		if (!redir_file(file, 'w'))
			return (0);
	}
	if (!ft_test_cmd(env, cmd))
		return (0);
	return (do_redir(env, file, cmd, op));
}
