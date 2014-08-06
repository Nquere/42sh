/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 04:44:48 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:51:27 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*cpy;

	new = ft_strnew(s);
	cpy = new;
	while (*s)
	{
		*cpy = f(*s);
		cpy++;
		s++;
	}
	return (new);
}
