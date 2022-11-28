/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_hdoc_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasha <pasha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:46:17 by pguranda          #+#    #+#             */
/*   Updated: 2022/11/28 22:00:20 by pasha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int is_heredoc(t_prs_tok *prs_tok, t_minishell *data)
{
	t_prs_tok	*tmp;
	int			num_hdoc;

	tmp = prs_tok;
	num_hdoc = 0;
printf("count1\n");
		if (tmp->type == HEREDOC)
			data->hdoc->num_hdocs++;


	return (num_hdoc);
}

/*Destroys the temp files created by hdocs
IMPORTANT: path to the file i.e. its name
is matching the index of the hdoc*/
void	destroy_hdocs(t_minishell *data)
{
	int	i;
	char	*path_to_hdoc;

	if (data->hdoc->fd_tmp == NULL)
		return ;
	while (data->hdoc->fd_tmp[i])
	{
		close(data->hdoc->fd_tmp[i]);
		i++;
	}
	path_to_hdoc = ft_itoa(data->hdoc->index);
	i = 0;
	unlink(path_to_hdoc);
	free(path_to_hdoc);
}

int	count_hdocs(t_minishell *data)
{
	t_header_prs_tok *tmp_prs_lst;
	int	i;

	tmp_prs_lst = data->lst_prs;
	i = 0;
	while (tmp_prs_lst != NULL)
	{
		printf("count\n");
		// data->hdoc->num_hdocs += is_heredoc(data->lst_prs->prs_tok);
		is_heredoc(tmp_prs_lst->prs_tok, data);
		tmp_prs_lst = tmp_prs_lst->next;
	}
	return (EXIT_SUCCESS);
}
