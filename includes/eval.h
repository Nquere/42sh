/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquere <nquere@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 17:27:21 by nquere            #+#    #+#             */
/*   Updated: 2014/06/23 17:52:04 by nquere           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/tree.h"

typedef enum	e_type
{
	COM,
	ARG,
	OR,
	AND,
	PIPE,
	RED,
	ERROR
}				t_type;

typedef struct	s_token
{
	enum e_type		type;
	char			*content;
}				t_token;

t_token			*ft_token_new(char *content, t_type type);
t_token			*ft_token_dup(t_token *token);
int				ft_token_put(t_token *token);
int				ft_token_del(t_token **token);
t_type			ft_token_get_type(t_token *token);
char			*ft_token_get_str(t_token *token);
int				ft_token_set_type(t_token *token, t_type type);
int				ft_token_set_str(t_token *token, char *str);
void			test2(char *cmd, char **env);
int				ft_test_word(char *str);
t_list			*newlexer(char *cmd, char **env);
t_tree			*newparser(t_list *list);
t_token			*read_cmd(t_list **list);
int				rules_exp(t_list **list, t_tree **ast);
void			burn_tree(t_tree *ast, char **env);
int				ft_add_cmd(char **env, char *cmd1, char *cmd2, char *str);

#endif
