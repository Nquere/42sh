/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:53:55 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:24:09 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strdup(const char *s1)
{
	char	*new;

	new = (char *)malloc(sizeof(s1) * ft_strlen(s1) + 1);
	ft_bzero(new, ft_strlen(s1) + 1);
	return (ft_memcpy(new, s1, ft_strlen(s1)));
}
