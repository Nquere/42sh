/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh2.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 16:15:33 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/18 18:22:35 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH2_H
# define FT_SH2_H

# include "../libft/includes/libft.h"

int		ft_builtins(char ***env, char *cmd);
int		ft_env(char ***env, char *cmd);
int		ft_changedir(char ***env, char *cmd);
char	*ft_listtochar(t_list *list, char *sep);
int		ft_setenv(char ***env, char *cmd);
int		ft_unsetenv(char ***env, char *key);
int		lexer(char *cmd, char **env);

#endif
