/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 04:23:22 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:25:26 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strnew(size_t n)
{
	char	*new;

	new = (char *)malloc(sizeof(new) * n + 1);
	ft_bzero(new, n + 1);
	return (new);
}
