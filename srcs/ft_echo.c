/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/10 21:52:47 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 17:01:44 by jalula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>

static int	ft_echo_print(char **split)
{
	char	*fsub;

	if (!(fsub = ft_strsub(*split, (ft_strlen(*split) -
			(ft_strlen(ft_strchr(*split, '"')) - 1)),
				ft_strlen(ft_strchr(*split, '"')))))
		return (-1);
	if (!(ft_strchr(*split, '"')))
		ft_putstr(*split);
	else
		ft_putstr(fsub);
	ft_putchar(' ');
	ft_strdel(&fsub);
	return (0);
}

int			ft_echo(char *cmd)
{
	char	**split;
	char	**fsplit;
	char	*ftrim;
	int		i;

	i = 0;
	if (!(ftrim = ft_strtrim_c(cmd), ' '))
		return (-1);
	if (!(split = ft_strsplit(ftrim, ' ')))
		return (-1);
	fsplit = split;
	split++;
	while (*split)
	{
		if (!(ft_strequ(*split, "-n")))
			ft_echo_print(split);
		else
			i = 1;
		split++;
		if (!(*split) && i == 0)
			ft_putchar('\n');
	}
	ft_destroysplit(fsplit);
	ft_strdel(&ftrim);
	return (1);
}
