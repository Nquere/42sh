/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:38:37 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:42:22 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_putstr(const char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	else
		write(1, "(null)", 6);
}
