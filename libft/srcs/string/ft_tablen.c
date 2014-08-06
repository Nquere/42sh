/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 19:10:14 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:57:15 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_tablen(char **tab)
{
	size_t	len;

	if (!tab)
		return (0);
	len = 0;
	while (tab[len])
		len++;
	return (len);
}
