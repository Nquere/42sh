/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 23:12:07 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:51:43 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*s;

	s = s1;
	while (*s)
		s++;
	ft_memcpy(s, s2, n);
	return (s);
}
