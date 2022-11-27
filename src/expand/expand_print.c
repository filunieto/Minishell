/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 01:57:56 by fnieves-          #+#    #+#             */
/*   Updated: 2022/11/27 14:52:09 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//Tokens no parsed
void	print_list(t_list_token *list)
{
	t_nod_token	*temp;
	int i = 0;
	if (!list)
	{
		printf("List does not exist which does not mean is leer\n");
		return;
	}
	if (!list->head)
	{
		printf("List exists but with no nodes\n");
		return;
	}
	temp = list->head;
	printf("-------Information from list----------\n");
	while(temp)
	{
		if (temp->quote)
			printf("Elemnt: %i, value= %s, type = %c, \n",i ,temp->name, temp->flag );
		// else if (temp->double_quote)
		// 	printf("Elemnto: %i, valor= %s, tipo = %c, double quot ON =%i \n",i ,temp->name, temp->flag, temp->double_quote);
		else
			printf("Elemnt: %i, value= %s, type = %c. \n",i ,temp->name, temp->flag  );
		i++;
		temp = temp->next;
	}
	printf("-------END  IMPRESION  lista-------\n");
}

void print_token(t_nod_token	*token)
{
	if (!token)
	{
		printf("token apunta  anull\n");
		return;
	}
	printf("-------imprimirmpos valores det oken----------\n");
	printf("el valor de name: %s y valor %c\n", token->name, token->flag);
	printf("-------END  IMPRESION  TOKEN-------\n");

}


// To delete? keep going here

void	print_list_parsedtoken(t_minishell *data)
{
	int i = 0;
	t_prs_tok *current_parsedtoken;
	//t_sublist_prs_tok	*current_sublist;
	printf("\n-------BEGIINING from list of parsed tokens----------\n");
	if (!data->array_sublist)
	{
		printf("-------El array no apunta a nada----------\n");
		printf("-------END from list of parsed tokens----------\n");
		return ;
	}
	while (data->array_sublist[i])
	{
		int j = 0;
		if (!data->array_sublist[i])
		{
			printf(" Subliste %i esta vacia y no deberia imprimir mas\n", i);
		}
		else //cambia l acondicion
		{
			printf("Start of PIPE %i , number of commands: %i (!= 1, error))\n", i, data->array_sublist[i]->number_cmd);
			current_parsedtoken = data->array_sublist[i]->first_prs_tok;
			while (current_parsedtoken)
			{
				printf("	nodo %i de Subliste %i. ", j, i);
				if (current_parsedtoken->type == COMMAND)
				{
					printf(" COMMAND: \n");
					int k = 0;
					//printf("   fuera Argumento %i, comando:|%s| \n",k , current_parsedtoken->cmd_flags[k]);
					while (current_parsedtoken->cmd_flags[k])
					{
						printf("	- Flag %i :|%s| \n",k , current_parsedtoken->cmd_flags[k]);
						k++;
					}
				}
				else if (ft_strchr(REDIRECT, current_parsedtoken->type))
				{
					printf(" REDIRECT: |%c| \n	-file name: |%s| \n", current_parsedtoken->type, current_parsedtoken->word);	
				}
				else
					printf("what kind of fucking parsed token are you printing?? \n");
				j++;
				current_parsedtoken = current_parsedtoken->next;
			}
		}
		i++;
	}
	printf("\n-------END from list of parsed tokens----------\n");
}

//another way printing