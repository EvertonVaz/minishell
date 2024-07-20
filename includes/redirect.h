/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:13:54 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/20 19:26:44 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# include "structs.h"

int		heredoc(char **delim, char count);
int		redir_out(t_token *tokens, t_token_type type);
void	move_redirect(t_token **tokens);
void	move_redirect_right(t_token **arch, t_token **word);
void	handle_redir(t_ast *root);
int		ft_puterror(char *cmd, char *str);
void	free_list(t_fds **fds);
void	dup_and_close(int *std_fd);
void	save_fds(int *fds, int close_fds);
void	capture_heredoc(t_token **token_list);
t_fds	**fds_list(char **name, int type);
void	save_fds(int *fds, int close_fds);
int		is_directory(char *name);

#endif