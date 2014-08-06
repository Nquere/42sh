/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 01:18:38 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/24 02:52:50 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		seek_b(char *str, char *a)
{
	if (*str == *a)
	{
		while (*a)
		{
			if (*str != *a)
				return (0);
			str++;
			a++;
		}
		return (1);
	}
	return (0);
}

static char		*add_c(char *str, char a)
{
	char	*tmp;
	char	*new;

	tmp = ft_strnew(1);
	tmp[0] = a;
	new = ft_strjoin(str, tmp);
	ft_strdel(&tmp);
	return (new);
}

char			*ft_replace(char *str, char *a, char *b)
{
	char	*new;
	char	*tmp;
	int		i;

	i = 0;
	if (!str || !a || !b)
		return (NULL);
	if (!ft_strstr(str, a))
		return (ft_strdup(str));
	new = ft_strnew(1);
	while (str[i])
	{
		tmp = new;
		if (seek_b(&(str[i]), a))
		{
			new = ft_strjoin(tmp, b);
			i = i + ft_strlen(a) - 1;
		}
		else
			new = add_c(tmp, str[i]);
		ft_strdel(&tmp);
		i++;
	}
	return (new);
}
