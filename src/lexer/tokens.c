/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:41:05 by egeraldo          #+#    #+#             */
/*   Updated: 2024/03/15 09:56:38 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_write_types(t_token *list)
{
	if (list->data[0] == '|' && list->data[1] == '|')
		return ((void)(list->type = OR));
	if (list->data[0] == '&' && list->data[1] == '&')
		return ((void)(list->type = AND));
	if (list->data[0] == '>' && list->data[1] == '>')
		return ((void)(list->type = REDIR_APPEND));
	if (list->data[0] == '<' && list->data[1] == '<')
		return ((void)(list->type = HEREDOC));
	if (list->data[0] == '|')
		return ((void)(list->type = PIPE));
	if (list->data[0] == '>')
		return ((void)(list->type = REDIR_OUT));
	if (list->data[0] == '<')
		return ((void)(list->type = REDIR_IN));
	if (list->data[0] == '"' && list->prev && !is_redirect(list->prev->type))
		return ((void)(list->type = DQUOTE));
	if (list->data[0] == '\'' && list->prev && !is_redirect(list->prev->type))
		return ((void)(list->type = QUOTE));
	if (list->data[0] == '(')
		return ((void)(list->type = BLOCK));
	if (list->prev && is_redirect(list->prev->type) && list->type == WORD)
		return ((void)(list->type = ARCHIVE));
}

void	stack_fill(t_token *list)
{
	list->data = "";
	list->type = 0;
	list->next = NULL;
	list->prev = NULL;
}

void	append_node(t_token **list, char *content)
{
	t_token	*node;
	t_token	*last_node;

	if (list == NULL)
		return ;
	node = malloc(sizeof(t_token));
	if (node == NULL)
		return ;
	stack_fill(node);
	node->next = NULL;
	node->data = content;
	if (*list == NULL || (*list)->data == NULL)
	{
		*list = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*list);
		last_node->next = node;
		node->prev = last_node;
	}
	ft_write_types(node);
}

int	list_fill(t_token **list, char *readline)
{
	char	*token;
	int		call;

	call = 0;
	token = " ";
	while (token && *token != '\0')
	{
		token = ft_strtok(readline, call++);
		if (token && *token != '\0')
			append_node(list, token);
	}
	holder_tokens(*list, 0);
	free(token);
	return (0);
}
