/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:16:20 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/25 00:27:15 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unix.h>
#include <libft.h>

char	*ft_getenv(char **env, char *name)
{
	if (!env || !name)
		return (NULL);
	if (!*env)
		return (NULL);
	while (*env && ft_strncmp(*env, name, ft_strlen(name)))
		env++;
	if (*env)
		return (ft_strdup(ft_strchr(*env, '=') + 1));
	else
		return (NULL);
}
