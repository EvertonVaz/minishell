/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:28:13 by egeraldo          #+#    #+#             */
/*   Updated: 2024/02/07 15:21:05 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(void)
{
	t_token *token_list = NULL;
	t_token *temp;
	t_envs **var_envs = create_envs_table();
	char *get_cmd;
	int i;
	//setup_signals();

	while (1)
	{
		get_cmd = ft_readline();
		// heredoc("result_heredoc", "eof", *var_envs);
		if (list_fill(&token_list, get_cmd, *var_envs) != 0)
			continue;
		i = parser(&token_list, var_envs);
		if (i == 3)
			break;
		temp = token_list;
		printf("\n-------------------------------------------------------------\n");
		while(temp)
		{
			if (temp->data == NULL)
				break;
			char *chatao = expand_var(temp->data, *var_envs);
			chatao = ft_remove_quotes(chatao);
			printf("data: %s  \t  type: %d\n", chatao, temp->type);
			temp = temp->next;
			free(chatao);
		}
		printf("\n-------------------------------------------------------------\n");
		free(get_cmd);
		free_token_list(token_list);
		token_list = NULL;
	}
	free(get_cmd);
	free_token_list(token_list);
	free_env_list(*var_envs);
	return (0);
}
