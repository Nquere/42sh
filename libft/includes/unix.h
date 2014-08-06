/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 12:54:47 by luccasim          #+#    #+#             */
/*   Updated: 2014/06/23 16:08:10 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIX_H
# define UNIX_H

char	*ft_getenv(char **env, char *name);
int		ft_file_exist(char *file);
int		ft_test_cmd(char **env, char *cmd);
int		ft_test_file(char *file);
int		ft_execve(char **env, char *cmd);
int		ft_redir(char **env, char *cmd1, char *op, char *cmd2);
void	ft_pipe(char **env, char *cmd1, char *cmd2);

#endif
