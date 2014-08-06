/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/02 09:17:57 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/18 22:19:38 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

int		ft_error(char const *name, char *str)
{
	char	*error;

	if (str)
		error = ft_strjoin(name, str);
	else
		error = (char *)name;
	ft_putendl_fd(error, 2);
	if (str)
		free(error);
	return (0);
}
