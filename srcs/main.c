/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 16:17:04 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/10 22:48:34 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"
#include <signal.h>
#include <sys/types.h>
#include "eval.h"

static void		my_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		ft_putstr("~>");
		return ;
	}
}

static char		*epur_line(char *line)
{
	char		*new;
	char		*last;
	char		*cmd;
	char		*pid;

	pid = ft_itoa(getpid());
	new = ft_replace(line, "\t", " ");
	last = ft_replace(new, "$$", pid);
	ft_strdel(&pid);
	ft_strdel(&line);
	cmd = ft_strtrim(last);
	ft_strdel(&new);
	ft_strdel(&last);
	return (cmd);
}

static void		exec_cmd(char *line, char ***env)
{
	char	**cmd;
	char	**tmp;

	if (!(cmd = ft_strsplit(line, ';')))
		return ;
	tmp = cmd;
	ft_strdel(&line);
	while (*tmp)
	{
		*tmp = epur_line(*tmp);
		if (!ft_builtins(env, *tmp))
			test2(*tmp, *env);
		tmp++;
	}
	ft_destroysplit(cmd);
}

int				main(int ac, char **av, char **env)
{
	char	*line;
	int		ret;

	line = NULL;
	env = ft_sstrdup(env);
	signal(SIGINT, my_handler);
	while (av && ac)
	{
		ft_putstr("~>");
		ret = get_next_line(0, &line);
		if (ret == 0)
			ft_fatal_error("", NULL);
		if (ret == -1)
			ft_fatal_error("open() on fd = 0 failed.", NULL);
		exec_cmd(line, &env);
	}
	return (0);
}
