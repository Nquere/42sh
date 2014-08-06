/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 09:26:35 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/19 19:33:00 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_fatal_error(const char *name, char *str)
{
	ft_error(name, str);
	if (str)
		ft_putendl_fd("Fatal error, Program will be exit", 2);
	_exit(0);
}
