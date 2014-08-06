/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:16:27 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:59:44 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	const char	*src;
	char		*dst;

	src = s2;
	dst = s1;
	while (n)
	{
		*dst++ = *src++;
		n--;
	}
	return (s1);
}
