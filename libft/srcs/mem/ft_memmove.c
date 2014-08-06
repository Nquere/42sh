/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:22:12 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:23:45 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char			*tmp;
	char			*dst;
	const char		*src;

	dst = s1;
	src = s2;
	tmp = (void *)malloc(sizeof(s1) * n + 1);
	ft_bzero(tmp, n + 1);
	ft_memcpy(tmp, s1, n);
	ft_memcpy((void *)s2, tmp, n);
	return (s1);
}
