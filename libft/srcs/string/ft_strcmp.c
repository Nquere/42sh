/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 19:25:37 by luccasim          #+#    #+#             */
/*   Updated: 2014/03/16 18:49:00 by sebgoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strcmp(char const *s1, char const *s2)
{
	int		t1;
	int		t2;
	int		max;

	t1 = ft_strlen(s1);
	t2 = ft_strlen(s2);
	max = (t1 > t2) ? t1 : t2;
	return (ft_memcmp(s1, s2, max));
}
