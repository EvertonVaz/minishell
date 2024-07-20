/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:14:22 by codespace         #+#    #+#             */
/*   Updated: 2024/07/20 19:26:44 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_token_type
{
	WORD,
	QUOTE,
	DQUOTE,
	BLOCK,
	ARCHIVE,
	PIPE,
	HEREDOC,
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	OR,
	AND,
	EXEC
}					t_token_type;

typedef struct s_token
{
	char			*data;
	t_token_type	type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_envs
{
	char			*key;
	char			*value;
	struct s_envs	*next;
}					t_envs;

typedef struct s_ast
{
	char			**cmd_list;
	t_token_type	type;
	int				fd;
	struct s_ast	*right;
	struct s_ast	*left;
}					t_ast;

typedef struct s_fds
{
	char			**name;
	int				type;
	struct s_fds	*next;
}					t_fds;

#endif