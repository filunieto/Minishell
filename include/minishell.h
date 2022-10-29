/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:16:01 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/29 19:44:27 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "struct.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/param.h> //check if it is fine to include
# include <readline/readline.h>
# include <readline/history.h>




typedef struct s_input
{
	char	*line;
	char	*prompt_name;
}	t_input;

//Linked list for the env
typedef struct s_env
{
	char		*key;
	char		*value;
	struct s_env *next;
}	t_env;

void	execute(char *line_buffer);
int		builtin_echo(char **args_echo);
int		builtin_pwd(char *args_cd);
char	**dup_matrix(char **matrix);
t_env	*ft_node_init(char *envp);
t_env	*ft_initializer(char **envp);
void	ft_lstadd_back_mini(t_env **lst, t_env *new);
char	*ft_copy_key(char *string);
void	print_2d(char **array);
int		count_strings(char **array);
void	print_env_lst(t_env *env_lst);
void	ft_lst_free(t_env *lst);
void	ft_free_2d(char **table);
t_env	*ft_lstlast_mini(t_env *lst);
void	ft_lstadd_back_mini(t_env **lst, t_env *new);
t_env	*ft_lstnew_env(char *value, char *key);


// DE FELIPE
#include <stdint.h> //para trabajr desde casa

// DEFINE SEPARATORS: metacharacter 
# define SPACE				' '
# define SINGLE_QUOTE		'\''
# define DOUBLE_QUOTE		'\"'
# define DOLLAR				'$'
# define REDIRECT_IN		'<'
# define REDIRECT_OUT		'>'
# define PIPE				'|'
# define SLASH				'/'

//TOKEN FLAGS:
# define TYP_WORD				1
# define TYP_REDIRECT_IN		2
# define TYP_REDIRECT_OUT		3
# define TYP_APPEND				4
# define TYP_HEREDOC			5
# define TYP_PIPE				6

/* My structures */

//mis funciones 

//para borrar

void	ft_parser(t_list_token *list, char *line);
void add_toke_list(t_list_token *list, t_nod_token *new);
t_nod_token *create_tok(t_lexing *lex_struct);
t_nod_token *find_last_node(t_list_token *list);
void	delete_list(t_list_token *list);
void init_list_tok(t_list_token *list);
void	creat_lst_tok(t_list_token *list, char **array_w);

//lexer.c
void	initializer_lex(t_lexing *lex_struct);
void	ft_lexer(t_list_token *list, char *line);
void	lexer_word(t_list_token *list, t_lexing *lex_struct, char *line);
char *ft_strjoin_char(char *buff, char c); //poner esta en libft

//lexer.tools
int ft_isspace(char c);
int ft_ismeta(char c);



void free_array_list(t_list_token *list, char **array_w);
void	free_array(char **array_w);
void	print_list(t_list_token *list);
void print_token(t_nod_token	*token);


void	check_leaks(void);


#endif 