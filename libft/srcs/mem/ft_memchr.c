/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:36:00 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:35:21 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*(char *)s == (unsigned char)c)
			return ((void *)s);
		n--;
		s++;
	}
	return (NULL);
}
