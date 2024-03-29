/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:15:13 by egeraldo          #+#    #+#             */
/*   Updated: 2024/03/19 12:44:03 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "structs.h"

int		ft_handle_quote(char *str, char quote, int check_close);
int		ft_handle_block(char *str, int check_close);
int		block_checker(t_token *tokens);
int		is_symbol(char *res);
char	*ft_strtok(char *str, int call);
char	*free_static(char *res, int i, int j);
int		stack_len(t_token *list);
t_token	*find_last_node(t_token *head);
void	stack_fill(t_token *list);
void	append_node(t_token **list, char *content);
int		list_fill(t_token **list, char *readline);
void	ft_write_types(t_token *list);
void	free_token_list(t_token **list);
void	print_error(int error);
int		check_syntax_and_quotes(t_token **list, char *readline);
t_token	*holder_tokens(t_token *tokens, int is_free);
int		check_is_directory(t_token **list, char *readline);

#endif