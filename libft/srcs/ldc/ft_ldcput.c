/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldcput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 01:05:34 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:29:14 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ldc.h>

void	ft_ldcput(t_ldc *list, void(*aff)())
{
	if (!list)
		return ;
	else if (!list->content)
		ft_putendl(NULL);
	else
		aff(list->content);
}
