/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <luccasim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 22:05:25 by luccasim          #+#    #+#             */
/*   Updated: 2014/05/18 22:18:43 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "ldc.h"
# include "unix.h"
# include "list.h"
# include "gnl.h"

void	*ft_memset(void *b, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	*ft_memmove(void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *s, const char *s2);
char	*ft_strnstr(const char *s, const char *s2, size_t n);
int		ft_strcmp(char const *s1, char const *s2);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t n);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s1, unsigned int i, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_strsplit(char const *s, char c);
char	*ft_itoa(int n);
void	ft_puttab(char **tab);
void	ft_putstr(const char *str);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putendl(const char *str);
void	ft_putendl_fd(const char *str, int fd);
void	ft_putnbr(int nb);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
int		ft_error(const char *name, char *str);
void	ft_fatal_error(const char *name, char *str);
void	ft_destroysplit(char **split);
size_t	ft_tablen(char **tab);
char	**ft_sstrdup(char **tab);
char	*ft_implode(char **tab, char const *sep);
char	*ft_replace(char *str, char *a, char *b);
char	*ft_strtrim_c(char const *s);
int		ft_parse_option(char **a, char **o, t_list **l, int(*s)(char c));

#endif
