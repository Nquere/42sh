/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroysplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 19:02:03 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/27 09:55:02 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_destroysplit(char **str)
{
	char	**f;

	if (!str)
		return ;
	f = str;
	while (*str)
	{
		free(*str);
		*str = NULL;
		str++;
	}
	free(f);
	f = NULL;
}
