/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:13:52 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/28 16:20:31 by pguranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	create_pipe(t_minishell *data)
{
	if (pipe(data->pipe) < 0)
	{
		perror(NULL);
		// free_cmd_and_path(data);
		return (-1);
	}
	return (0);
}

int	create_fork(t_minishell *data)
{
	// signal(SIGINT, SIG_IGN);
	data->pid = fork();
	if (data->pid < 0)
	{
		perror(NULL);
		// free_cmd_and_path(data);
		return (-1);
	}
	return (0);
}

void	exec_bash_cmd(t_minishell *data)
{
	if (data->ex_error == true)
	{
		reset_stdin_stdout(data);
		// exec_error(CMD_NOT_FOUND, data->exec->cmd[0]);
		exit(CMD_NOT_FOUND);
	}
	else
	{
		if (execve(data->exec->exec_path, data->exec->cmd_flags, (char * const*)data->env_lst) < 0)
		{
			reset_stdin_stdout(data);
			// exec_error(CMD_NOT_FOUND, data->exec->cmd[0]);
			exit(CMD_NOT_FOUND);
		}
	}
	exit(EXIT_SUCCESS);
}