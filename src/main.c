/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <etovaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:28:13 by egeraldo          #+#    #+#             */
/*   Updated: 2024/03/09 18:54:46 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	pid_last_exit_status(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	if (status == 139)
		status = 1;
	update_status_error(status);
}

int	update_status_error(int exit_status)
{
	static int	status;

	if (exit_status != -1)
		status = exit_status;
	return (status);
}

void	free_program(t_ast **root, char **get_cmd, t_envs **var_envs)
{
	if (get_cmd && *get_cmd)
		free(*get_cmd);
	if (root && *root)
	{
		free_ast(*root, 0);
		*root = NULL;
	}
	if (var_envs && *var_envs)
		free_env_list(*var_envs);
}

int	main(void)
{
	t_token	*token_list;
	t_ast	*root;
	char	*get_cmd;
	t_envs	**var_envs;

	token_list = NULL;
	// setup_signals();
	var_envs = create_envs_table(0, 0);
	root = NULL;
	while (1)
	{
		get_cmd = ft_readline();
		/* if (ft_strncmp(get_cmd, "exit", 4) == 0) // APAGAR
			ft_exit(0); */
		root = parser(token_list, get_cmd);
		if (!root)
			continue ;
		starting_exec(root);
		root = ast_holder(NULL, 1, 0);
		free_program(&root, &get_cmd, NULL);
		token_list = NULL;
	}
	free_program(&root, &get_cmd, var_envs);
	close_fds(NULL, 1);
	return (0);
}
