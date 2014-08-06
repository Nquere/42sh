/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 16:36:30 by nquere            #+#    #+#             */
/*   Updated: 2014/06/23 17:49:14 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"

static int	ft_add(char **env, char *cmd1, char *cmd2)
{
	int		ret;

	ret = ft_execve(env, cmd1);
	if (ret)
		return (1);
	ft_execve(env, cmd2);
	return (0);
}

int			ft_add_cmd(char **env, char *cmd1, char *cmd2, char *str)
{
	if (!cmd1 || !cmd2 || !env)
		return (1);
	if (ft_strequ(str, "&&"))
		return (ft_add(env, cmd1, cmd2));
	if (ft_strequ(str, "||"))
	{
		if (ft_execve(env, cmd1) != 0)
		{
			ft_execve(env, cmd2);
			return (0);
		}
		else
			return (1);
	}
	return (1);
}
