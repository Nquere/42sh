/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 19:49:52 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/18 22:44:33 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl(const char *str)
{
	if (!str)
		ft_putstr_fd("(NULL)", 2);
	else
		ft_putstr(str);
	ft_putchar('\n');
}
