/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 23:07:12 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:46:01 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char	*s;

	s = s1;
	while (*s)
		s++;
	ft_memcpy(s, s2, ft_strlen(s2) + 1);
	return (s1);
}
