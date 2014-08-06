/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 19:35:48 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/14 17:06:08 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sh2.h"

static void		delenv(char ***env, char *key)
{
	char		**new;
	char		**old;
	size_t		s_env;
	size_t		i;
	size_t		j;

	old = *env;
	s_env = ft_tablen(old);
	new = (char **)malloc(sizeof(char *) * s_env);
	i = 0;
	j = 0;
	if (new)
	{
		while (j < s_env)
		{
			if (ft_strncmp(old[j], key, ft_strlen(key)))
				new[i++] = ft_strdup(old[j]);
			j++;
		}
		new[i] = NULL;
		ft_destroysplit(old);
		*env = new;
	}
}

static void		get_newenv(char ***env, char **arg)
{
	char	*search;

	arg++;
	while (*arg)
	{
		if ((search = ft_getenv(*env, *arg)))
		{
			delenv(env, *arg);
			ft_strdel(&search);
		}
		arg++;
	}
}

int				ft_unsetenv(char ***env, char *key)
{
	char		**arg;
	size_t		size;

	if (!env || !key)
		return (1);
	arg = ft_strsplit(key, ' ');
	size = ft_tablen(arg);
	if (size == 1)
		ft_putendl("unsetenv: Too few arguments.");
	else
		get_newenv(env, arg);
	ft_destroysplit(arg);
	return (1);
}
