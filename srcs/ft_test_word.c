/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 15:54:45 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 15:54:48 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

static int		is_word(char c)
{
	if (ft_isalnum(c))
		return (1);
	if (c == '.' || c == '+' || c == '-' || c == '_' || c == '?' || c == '@')
		return (1);
	return (0);
}

int				ft_test_word(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!is_word(*str))
			return (0);
		str++;
	}
	return (1);
}
