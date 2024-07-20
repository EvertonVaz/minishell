/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:04:56 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/20 19:25:40 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	splited_free(char **str, int words_len)
{
	while (words_len-- > 0)
		free(str[words_len]);
	free(str);
}

void	free_env_list(t_envs *list)
{
	t_envs	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list->key);
		free(list->value);
		free(list);
		list = tmp;
	}
}

int	is_redirect(int type)
{
	if ((type == REDIR_OUT || type == REDIR_APPEND
			|| type == REDIR_IN || type == HEREDOC))
		return (1);
	return (0);
}
