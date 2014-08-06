/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 12:59:26 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/10 12:59:32 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unix.h>
#include <libft.h>
#include <unistd.h>

static void		pipe_error(int error)
{
	if (error == 1)
		ft_error("pipe() failed", NULL);
	else if (error == 2)
		ft_error("fork() failed", NULL);
	_exit(0);
}

static int		ret_pipe(char **env, char *cmd1, char *cmd2)
{
	int		pfd[2];
	int		pid;

	if (pipe(pfd) == -1)
		return (1);
	if ((pid = fork()) == -1)
		return (2);
	if (pid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		close(pfd[0]);
		ft_execve(env, cmd2);
		return (3);
	}
	else
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		close(pfd[1]);
		ft_execve(env, cmd1);
		return (4);
	}
}

void			ft_pipe(char **env, char *cmd1, char *cmd2)
{
	int		pid;

	if (!ft_test_cmd(env, cmd1) || !ft_test_cmd(env, cmd2))
		return ;
	if ((pid = fork()) == -1)
		ft_error("fork() failed", NULL);
	if (pid == 0)
		pipe_error(ret_pipe(env, cmd1, cmd2));
	else
		wait(&pid);
}
