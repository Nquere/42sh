/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:47:03 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:44:33 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int nb, int fd)
{
	char	*number;

	number = ft_itoa(nb);
	ft_putstr_fd(number, fd);
	ft_strdel(&number);
}
