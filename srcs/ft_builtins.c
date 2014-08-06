/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 02:23:44 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/11 01:37:38 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_sh2.h>
#include <ft_42sh.h>
#include "eval.h"

int		ft_builtins(char ***env, char *cmd)
{
	if (!env || !cmd)
		return (0);
	if (ft_strequ("exit", cmd))
		_exit(0);
	if (ft_strnequ("setenv", cmd, 6))
		return (ft_setenv(env, cmd));
	if (ft_strnequ("unsetenv", cmd, 8))
		return (ft_unsetenv(env, cmd));
	if (ft_strnequ("env", cmd, 3))
		return (ft_env(env, cmd));
	if (ft_strnequ("cd", cmd, 2))
		return (ft_changedir(env, cmd));
	if (ft_strnequ("echo", cmd, 2))
		return (ft_echo(cmd));
	return (0);
}
