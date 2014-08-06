/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:11:01 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 19:00:01 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*s;

	s = b;
	while (len)
	{
		*s++ = (unsigned char)c;
		len--;
	}
	return (b);
}
