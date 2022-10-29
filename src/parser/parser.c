/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:13:48 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/29 16:40:36 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
/*recorremos carcater or caracter como en printf.
Empezamos una funcion en el que el modo single quotes o double quotes este inactivo
tenemos que ir guardando la posicion del inico de cadena y el final de cadena.
el final de cadena lo hacemos  null terminated , y guardamos e una variable temp, 
ese final de cadena si es uno de lo scrrractares  esp, | , , ,>
*/




// /*
// 	From the array separated by spaces, coming from prompt
// 	we create a node with the char , array[i],
// 	and add it to the end of the list
// */
// void	creat_lst_tok(t_list_token *list, char **array_w) //funcion para borrar
// {
// 	int i;
// 	t_nod_token *new;
	
// 	new = NULL;
// 	i = 0;
// 	if(!array_w[i]) // la lista de argumentos esta vacia
// 	{
// 		printf("the line is empty. prompt again and free array and list?\n");
// 		free_array_list(list, array_w);
// 		return ; //o quuiza es un exit , para poder seguir poiniendo el prompt
// 	}
// 	while (array_w[i])
// 	{
// 		new = create_tok(array_w[i]);
// 		if (!new) //si hay algun problema en la creacion del nodo, liberar todo y return
// 		{
// 			free_array_list(list, array_w); //es la misma funcion que arriba?
// 			return ;
// 		}
// 		add_toke_list(list, new); //vamos a pasar a lista
// 		i++;
// 		//si hay algun probema, hacer un free, de toda la lista
// 	}
// 	free_array(array_w);
// }



// void	free_array(char **array_w)
// {
// 	int i;

// 	i = -1;
// 	while (array_w[++i])
// 	{ 
// 		free(array_w[i]);
// 	}
// 	free(array_w);
// }

// void free_array_list(t_list_token *list, char **array_w)
// {
// 	free_array(array_w);
// 	delete_list(list);
// }

// //atexit(check_leaks);
// void	check_leaks(void)
// {
// 	system("leaks minishell");
// }

// void	ft_parser(t_list_token *list, char *line)
// {
// 	// char	**array_w;

// 	// array_w = NULL;
// 	// array_w = ft_split((const char*)line, SPACE);
	
// 	init_list_tok(list);
// 	creat_lst_tok(list, line);
// 	//vamos limpiando paso por paso la lista 
// 	//printf("imprime linea en programa ft_parser: %s\n", line);
// 	print_list(list);
// 	delete_list(list); //para que no queden leaks
// 	//system("leaks minishell");
	
// }

// //second round parsing. Indicate if element are before a delimeter , after or in between