/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 08:18:02 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/23 15:58:35 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	**add_path_sign(char **path_to_builtins)
{
	char	**builtin_paths_final;
	int		line_count;
	int		i;

	i = 0;
	line_count = count_strings(path_to_builtins);
	builtin_paths_final = malloc(sizeof(char *) * line_count);
	if (builtin_paths_final == NULL)
		return (NULL);
	while (path_to_builtins[i] != NULL)
	{
		builtin_paths_final[i] = ft_strjoin(path_to_builtins[i], "/");
		i++;
	}
	builtin_paths_final[i] = NULL;
	return (builtin_paths_final);
}

char	*check_paths(char **path_to_builtins, char *command)
{
	char	*string_to_check;
	int		i;

	i = 0;
	while (path_to_builtins[i] != NULL)
	{
		string_to_check = ft_strjoin(path_to_builtins[i], command);
		if (access(string_to_check, F_OK) == 0)
			return (string_to_check);
		else
			i++;
	}
	printf("Error\nCorrect path not found");
	return (NULL);
}

char	**find_path(char **envp)
{
	char	*path;
	int		i;
	char	**path_to_builtins;

	path = NULL;
	i = 0;
	if (envp == NULL || *envp == NULL)
		return (NULL);
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = envp[i];
	path_to_builtins = ft_split(path + 5, ':');
	return (path_to_builtins);
}

int	find_correct_paths(t_prs_tok *parameters, t_minishell *data)
{
	char	**path_to_builtins;

	path_to_builtins = NULL;
	path_to_builtins = ft_split(ft_lst_find(data->env_lst, "PATH")->value, ':');
	if (path_to_builtins == NULL)
		return (EXIT_FAILURE);
	if (path_to_builtins == NULL)
		printf("Error\nCould not find the PATH =");
	path_to_builtins = add_path_sign(path_to_builtins);
	parameters->exec_path = \
		check_paths(path_to_builtins, parameters->cmd_flags[0]);
	if (parameters->exec_path == NULL)
		printf("Error\nPlease check cmd1");
	return (EXIT_SUCCESS);
}
