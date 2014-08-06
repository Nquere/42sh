/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 16:08:00 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/07 17:12:54 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unix.h>
#include <libft.h>
#include <libft.h>

static int	is_cmd(char *path, char *str)
{
	char	**split;
	char	*name;
	int		i;
	int		ret;

	if (!(split = ft_strsplit(path, ':')) || !str)
		return (0);
	i = 0;
	while (split[i])
	{
		path = ft_strjoin(split[i], "/");
		name = ft_strjoin(path, str);
		ft_strdel(&path);
		if (access(name, X_OK) == 0)
		{
			ft_destroysplit(split);
			ft_strdel(&name);
			return (1);
		}
		ft_strdel(&name);
		i++;
	}
	ft_destroysplit(split);
	return (ret = ((access(str, X_OK) == 0) ? 1 : 0));
}

int			ft_test_cmd(char **env, char *str)
{
	char	*path;
	char	**split;

	if (!(path = ft_getenv(env, "PATH=")) || !str)
		return (0);
	split = ft_strsplit(str, ' ');
	if (is_cmd(path, split[0]))
	{
		ft_destroysplit(split);
		ft_strdel(&path);
		return (1);
	}
	else
	{
		ft_error(str, ": command not found.");
		ft_destroysplit(split);
		ft_strdel(&path);
		return (0);
	}
}
