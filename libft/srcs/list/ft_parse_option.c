/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 00:49:04 by luccasim          #+#    #+#             */
/*   Updated: 2014/04/25 04:30:59 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		*my_realloc(char **str)
{
	char		*new;

	new = ft_strnew(ft_strlen(*str) + 1);
	if (*str)
		ft_strcpy(new, *str);
	ft_strdel(str);
	return (new);
}

static char		check_opt(char *arg, char **opt, int(*is)(char c))
{
	char		*new;
	int			i;

	i = 0;
	new = my_realloc(opt);
	while (new[i])
		i++;
	arg++;
	while (*arg)
	{
		*opt = new;
		if (is(*arg) == 0)
			return (*arg);
		else
		{
			if (ft_strchr(new, *arg) == NULL)
			{
				new[i++] = *arg;
				new = my_realloc(&new);
			}
		}
		arg++;
	}
	*opt = new;
	return (0);
}

static int		error_arg(char *name, char c, char **opt)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	write(2, &c, 1);
	write(2, "\n", 1);
	ft_strdel(opt);
	return (0);
}

int				ft_parse_option(char **av, char **opt, t_list **l,
								int(*is)(char c))
{
	char		fail;
	char		*name;

	if (!av || !is)
		return (0);
	name = *av++;
	while (*av)
	{
		if (**av != '-')
			break ;
		if (ft_strequ("-", *av) || ft_strequ("--", *av))
		{
			av++;
			break ;
		}
		if ((fail = check_opt(*av, opt, is)))
			return (error_arg(name, fail, opt));
		av++;
	}
	while (*av)
		ft_listaddtail(l, ft_strdup(*av++));
	return (1);
}
