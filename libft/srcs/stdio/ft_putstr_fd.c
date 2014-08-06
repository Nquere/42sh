/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:40:37 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 19:31:06 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_putstr_fd(const char *str, int fd)
{
	if (str)
		write(fd, str, ft_strlen(str));
	else
		write(fd, "(null)", 6);
}
