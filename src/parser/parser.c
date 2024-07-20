/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:45:05 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/20 19:26:44 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isin(char *str, char *set)
{
	int	i;

	i = 0;
	while (str && str[i] && ft_strchr(set, str[i]))
		i++;
	return (i);
}

t_ast	*parser(char *get_cmd)
{
	t_ast	*root;
	t_token	*token_list;

	root = NULL;
	token_list = NULL;
	if ((get_cmd && !*get_cmd) || list_fill(&token_list, get_cmd) != 0)
		return (NULL);
	move_redirect(&token_list);
	capture_heredoc(&token_list);
	if (check_syntax_and_quotes(&token_list, get_cmd))
		return (NULL);
	root = ast_constructor(token_list);
	ast_holder(root, 0, 0);
	return (root);
}
