/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natali <natali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:49 by egeraldo          #+#    #+#             */
/*   Updated: 2024/03/06 19:26:00 by natali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*free_static(char *res, int i, int j)
{
	char	*temp;

	if (res && res[0] == '\0')
		return (NULL);
	temp = ft_strdup(&res[i + j]);
	if ((temp && temp[0] == '\0') || ft_strncmp(res, temp, 125) == 0)
	{
		free(temp);
		temp = NULL;
	}
	free(res);
	res = NULL;
	return (temp);
}

int	stack_len(t_token *list)
{
	t_token	*current;
	int		count;

	count = 0;
	current = list;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_token	*find_last_node(t_token *head)
{
	if (head == NULL)
		return (NULL);
	while (head && head->next)
		head = head->next;
	return (head);
}

void	free_token_list(t_token **list)
{
	t_token	*tmp;

	while (list && *list)
	{
		tmp = (*list)->next;
		if (list && *list && (*list)->data && *(*list)->data)
		{
			free((*list)->data);
			(*list)->data = NULL;
		}
		free(*list);
		*list = tmp;
	}
	list = NULL;
}

void print_error(int error)
{
	if (error == PIPE)
		ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
	if(error == AND)
		ft_putstr_fd("syntax error near unexpected token `&&'\n", 2);
	if(error == OR)
		ft_putstr_fd("syntax error near unexpected token `||'\n", 2);
	if(error == 1)
		ft_putstr_fd("Minishell can't deal with open quotes\n", 2);
}
