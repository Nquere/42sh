/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 01:26:54 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/24 01:56:09 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_sstrdup(char **tab)
{
	char		**new;
	int			i;
	int			j;

	i = ft_tablen(tab) + 1;
	new = (char **)malloc(sizeof(char *) * i);
	if (new)
	{
		j = 0;
		while (j < i - 1)
		{
			new[j] = ft_strdup(tab[j]);
			j++;
		}
		new[j] = NULL;
	}
	return (new);
}
