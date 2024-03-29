/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:56:56 by etovaz            #+#    #+#             */
/*   Updated: 2024/03/18 15:35:54 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*search_type_to_split(t_token *tokens)
{
	t_token	*temp;

	temp = find_last_node(tokens);
	while (temp && (temp->type != AND && temp->type != OR))
		temp = temp->prev;
	if (temp && (temp->type == AND || temp->type == OR))
		return (temp);
	temp = find_last_node(tokens);
	while (temp && temp->type != PIPE)
		temp = temp->prev;
	if (temp && temp->type == PIPE)
		return (temp);
	temp = find_last_node(tokens);
	while (temp && !is_redirect(temp->type))
		temp = temp->prev;
	if (temp && is_redirect(temp->type))
		return (temp);
	return (NULL);
}

int	ast_split_node(t_ast *root, t_token *tokens, t_token *token_to_split)
{
	t_token	*right;
	t_token	*tmp;

	right = NULL;
	tmp = tokens;
	if (!root || !tokens || !token_to_split)
		return (0);
	right = token_to_split->next;
	if (right)
		right->prev = NULL;
	root->type = token_to_split->type;
	tmp = token_to_split->prev;
	if (tmp)
		tmp->next = NULL;
	root->left = ast_constructor(tmp);
	root->right = ast_constructor(right);
	return (1);
}

void	try_split_else_exec(t_ast *ast_node, t_token *tokens)
{
	char	**cmd;
	t_token	*to_split;
	int		type;

	to_split = search_type_to_split(tokens);
	type = -1;
	if (tokens)
		type = tokens->type;
	if (ast_split_node(ast_node, tokens, to_split))
	{
		if (to_split && ft_isin(to_split->data, "><|&"))
		{
			ast_node->type = to_split->type;
			free(to_split->data);
			free(to_split);
		}
		return ;
	}
	else
		cmd = command_constructor(&tokens);
	if (type >= 0 && type <= 2)
		ast_node->type = EXEC;
	else if (ast_node && type > 0)
		ast_node->type = type;
	ast_node->cmd_list = cmd;
}

char	**command_constructor(t_token **tokens)
{
	char	**cmd;
	t_token	*temp;
	int		i;

	while (tokens && *tokens && (*tokens)->prev)
		*tokens = (*tokens)->prev;
	temp = *tokens;
	i = 0;
	while (temp && ++i)
		temp = temp->next;
	cmd = ft_calloc(i + 1, sizeof(char *));
	temp = *tokens;
	i = 0;
	while (temp)
	{
		cmd[i] = ft_strdup(temp->data);
		temp = temp->next;
		i++;
	}
	cmd[i] = NULL;
	free_token_list(tokens);
	return (cmd);
}

t_ast	*ast_constructor(t_token *tokens)
{
	t_ast	*root;

	root = ft_calloc(1, sizeof(t_ast));
	try_split_else_exec(root, tokens);
	return (root);
}
