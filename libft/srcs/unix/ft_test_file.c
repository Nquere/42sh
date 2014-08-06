/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/07 17:41:45 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/07 17:47:45 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

int		ft_test_file(char *name)
{
	if (access(name, F_OK) == 0)
	{
		if (access(name, X_OK) == -1)
		{
			ft_error(name, ": Permission denied.");
			return (0);
		}
		return (1);
	}
	else
		ft_error(name, ": No such file or directory.");
	return (0);
}
