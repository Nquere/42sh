/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:40:59 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 19:06:02 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *src, const void *dst, size_t n)
{
	const char	*s1;
	const char	*s2;

	s1 = src;
	s2 = dst;
	if (((*s1 == '\0') && (*s2 == '\0')) || !n)
		return (0);
	else if (*s1 != *s2)
		return (*s1 - *s2);
	return (ft_memcmp(++s1, ++s2, --n));
}
