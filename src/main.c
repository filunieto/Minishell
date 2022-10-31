/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:26:30 by pguranda          #+#    #+#             */
/*   Updated: 2022/10/31 13:08:59 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//hay que inicializar la lista () con malloc??

void	initializer_data(t_minishell *data)
{
	t_list_token list;
	
	
	data->line = NULL;
	data->list = list;

	// data->list->head = list->head;
	// data->list->size = 0;
	data->list.head = NULL;
	data->list.size = 0;
	//init_list_tok(data->list);
}

/*
	atexit(check_leaks);
*/
void	check_leaks(void)
{
	system("leaks minishell");
}


/*Add - prompt, history, env linked list (env_lst)*/
//i think it does not free line at the end 
int main(int argc, char **argv, char **envp)
{
	// t_input		input;
	char *line_buffer;
	t_env *env_lst;
	char **dup_env;
	char	**after_split;
	
	//t_list_token	list; //reeemplazada por data
	t_minishell		data;

	initializer_data(&data);

	while (1)
	{
		data.line = NULL; //do we need it always?

		
		line_buffer = readline("minishell $ ");
		data.line = line_buffer;
		add_history(line_buffer); // is it &data.line ??
		// after_split = ft_split_meta(line_buffer);
		// print_2d(after_split);
		ft_lexer(&data);
		//atexit(check_leaks);

		//system("leaks minishell");

		//printf("till here ft_lexer ok \n");
		print_list(&data.list);
		delete_list(&data.list); //para que no queden leaks
		//ft_parser(&list, line_buffer);
		// dup_env = dup_matrix(envp);
		// env_lst = ft_initializer(dup_env);
		// // print_env_lst(env_lst);
		free(line_buffer);
		// free(data.line);
		// data.line = NULL;
		// ft_lst_free(env_lst);
		// ft_free_2d(dup_env);
		//atexit(check_leaks);
		//system("leaks minishell");
	}
	

	return (0);
}
