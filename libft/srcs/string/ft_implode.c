/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 18:25:06 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/25 18:26:58 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_implode(char **tab, char const *sep)
{
	char	*new;
	char	*tmp;
	char	*old;
	int		i;

	if (!tab)
		return (NULL);
	i = 0;
	new = ft_strdup(tab[0]);
	i++;
	while (tab[i])
	{
		tmp = ft_strjoin(sep, tab[i]);
		old = new;
		new = ft_strjoin(old, tmp);
		ft_strdel(&old);
		ft_strdel(&tmp);
		i++;
	}
	return (new);
}
