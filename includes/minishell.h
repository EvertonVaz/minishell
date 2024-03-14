/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:07:49 by egeraldo          #+#    #+#             */
/*   Updated: 2024/03/14 16:41:26 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "ast.h"
# include "builtin.h"
# include "exec.h"
# include "fcntl.h"
# include "lexer.h"
# include "parser.h"
# include "read.h"
# include "redirect.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

void	free_program(t_ast **root, char **get_cmd, t_envs **var_envs);
int		update_status_error(int i);
void	pid_last_exit_status(pid_t pid);

#endif