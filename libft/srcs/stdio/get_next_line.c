/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:32:50 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/18 22:57:21 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnl.h>

static char		*save_char(char *cpy)
{
	if (!cpy)
		return (NULL);
	while (*cpy)
	{
		if (*cpy == '\n')
			return (ft_strdup(++cpy));
		cpy++;
	}
	return (NULL);
}

static int		get_line(char *cpy, char **line)
{
	int		i;
	char	*new;

	i = 0;
	while (cpy[i] != '\n')
		i++;
	new = ft_strsub(cpy, 0, i);
	free(cpy);
	*line = new;
	return (1);
}

static char		*ft_realloc(char *s1, char const *s2)
{
	char	*new;

	if (!s1)
		s1 = ft_strnew(0);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	free(s1);
	return (new);
}

static int		last_word(char *cpy, char **line)
{
	if (cpy)
	{
		if (ft_strcmp(cpy, ""))
		{
			*line = cpy;
			return (1);
		}
		return (0);
	}
	else
		return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUF_SIZE + 1];
	char			*cpy;
	static char		*save = NULL;
	int				ret;

	cpy = save;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		buf[ret] = 0;
		cpy = ft_realloc(cpy, buf);
		if ((save = save_char(cpy)))
			return (get_line(cpy, line));
	}
	if ((save = save_char(cpy)))
		return (get_line(cpy, line));
	return (last_word(cpy, line));
}
