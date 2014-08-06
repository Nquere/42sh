/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:53:11 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 15:53:39 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static int		is_cmd(char *path, char *str)
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

static int		test_cmd(char **env, char *str)
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
		ft_destroysplit(split);
		ft_strdel(&path);
		return (0);
	}
}

static int		analizer(char *split, t_list **list, char **env)
{
	t_token		*token;

	token = NULL;
	if (test_cmd(env, split))
		ft_listaddtail(list, ft_token_new(split, COM));
	else if (ft_strequ(split, "||"))
		ft_listaddtail(list, ft_token_new(split, OR));
	else if (ft_strequ(split, "&&"))
		ft_listaddtail(list, ft_token_new(split, AND));
	else if (ft_strequ(split, "|"))
		ft_listaddtail(list, ft_token_new(split, PIPE));
	else if (ft_strequ(split, "<"))
		ft_listaddtail(list, ft_token_new(split, RED));
	else if (ft_strequ(split, ">"))
		ft_listaddtail(list, ft_token_new(split, RED));
	else if (ft_strequ(split, ">>"))
		ft_listaddtail(list, ft_token_new(split, RED));
	else if (ft_test_word(split))
		ft_listaddtail(list, ft_token_new(split, ARG));
	else
		ft_listaddtail(list, ft_token_new(split, ERROR));
	return (0);
}

static int		tokenizer(char *cmd, t_list **list, char **env)
{
	char		**split;
	char		**tmp;

	if (!(split = ft_strsplit(cmd, ' ')))
		return (ft_error("ft_strsplit in newlexer fail", NULL));
	tmp = split;
	while (*split)
	{
		analizer(*split, list, env);
		split++;
	}
	ft_destroysplit(tmp);
	return (0);
}

t_list			*newlexer(char *cmd, char **env)
{
	t_list		*list;

	list = NULL;
	if (!cmd)
		return (list);
	tokenizer(cmd, &list, env);
	return (list);
}
