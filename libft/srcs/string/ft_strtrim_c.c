/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalula <jalula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 18:37:50 by jalula            #+#    #+#             */
/*   Updated: 2014/06/23 18:37:51 by jalula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char			*ft_strtrim_c(char const *s)
{
	int		i;
	int		y;
	char	*s1;

	i = 0;
	y = 0;
	s1 = (char *)malloc(ft_strlen(s) + 1 * sizeof(*s1));
	if (s1 == NULL)
		return (NULL);
	while (s[i] == 34)
		i++;
	while (s[i])
	{
		s1[y] = s[i];
		i++;
		y++;
	}
	i--;
	while (s[i] == 34)
	{
		i--;
		y--;
	}
	s1[y] = '\0';
	return (s1);
}
