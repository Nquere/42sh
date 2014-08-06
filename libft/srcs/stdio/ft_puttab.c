/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/19 00:03:18 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/10 13:01:42 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_puttab(char **tab)
{
	if (!tab)
	{
		ft_putendl(NULL);
		return ;
	}
	if (!*tab)
	{
		ft_putendl(NULL);
		return ;
	}
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}
