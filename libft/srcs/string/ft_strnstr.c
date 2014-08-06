/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 01:07:10 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 19:20:37 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *s, const char *s2, size_t n)
{
	while (n && *s)
	{
		if (*s == *s2)
		{
			if (!ft_memcmp(s, s2, ft_strlen(s2)))
				return ((char *)s);
		}
		s++;
		n--;
	}
	return (NULL);
}
