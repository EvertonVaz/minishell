/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:03:10 by egeraldo          #+#    #+#             */
/*   Updated: 2024/03/12 16:13:07 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "structs.h"

t_token	*search_type_to_split(t_token *tokens);
int		ast_split_node(t_ast *root, t_token *tokens, t_token *token_to_split);
char	**command_constructor(t_token **tokens);
void	try_split_else_exec(t_ast *ast_node, t_token *tokens);
t_ast	*ast_constructor(t_token *tokens);
t_ast	*ast_holder(t_ast *root, int its_created, int is_free);
void	free_ast(t_ast *root);

#endif