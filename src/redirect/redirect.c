/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:01:00 by egeraldo          #+#    #+#             */
/*   Updated: 2024/03/06 10:50:18 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dup_and_close(int	*std_fd)
{
	if (!std_fd && !*std_fd)
		return ;
	dup2(std_fd[1], STDOUT_FILENO);
	dup2(std_fd[0], STDIN_FILENO);
	close_fds(std_fd, 0);
}

void	free_list(t_fds	**fds)
{
	t_fds	*tmp;

	if (!fds || !*fds)
		return ;
	while(*fds)
	{
		tmp = (*fds)->next;
		free(*fds);
		*fds = tmp;
	}
}

int	check_redirect(t_ast *root)
{
	if (root->type == REDIR_IN || root->type == REDIR_OUT
		|| root->type == REDIR_APPEND)
		return (1);
	return (0);
}

int	ft_puterror(char *cmd, char *str)
{
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	update_status_error(1);
	return (0);
}

t_fds	**init_fds(char **name, int type)
{
	static t_fds	*fds;
	t_fds			*new;

	if (!name && !type)
		return (&fds);
	new = malloc(sizeof(t_fds));
	new->name = name;
	new->type = type;
	new->next = NULL;
	new->next = fds;
	fds = new;
	return (&fds);
}

int	is_redir_in(char *name)
{
	int	fd;
	if (!access(name, F_OK))
	{
		fd = open(name, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else if (access(name, W_OK | R_OK))
		return(ft_puterror(name, ": Permission denied\n"));
	else
		return(ft_puterror(name, ": No such file or directory\n"));
	return (1);
}

int	is_redir_out(char *name, int type)
{
	int	fd;

	fd = -1;
	if (type == REDIR_OUT)
		fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	else if (type == REDIR_APPEND)
	{
		if (access(name, F_OK))
			fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0666);
		else
			fd = open(name, O_RDWR | O_APPEND, 0666);
	}
	if (fd < 0 && access(name, W_OK | R_OK))
		return(ft_puterror(name, ": Permission denied\n"));
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (1);
}

void	handling_redir(t_ast *root)
{
	if (root->left && check_redirect(root->left))
	{
		init_fds(root->right->cmd_list, root->type);
		handling_redir(root->left);
	}
	if (root->left->type == EXEC && check_redirect(root) && root->right)
		init_fds(root->right->cmd_list, root->type);
}

void	handle_redir(t_ast *root)
{
	//TODO: ARRUMAR O FLUXO QUANDO TIVER ALGUM PROBLEMA PARA ABRIR ARQUIVO
	int	std_fd[2];
	t_fds	**fds;
	t_fds	*tmp;

	std_fd[0] = dup(STDIN_FILENO);
	std_fd[1] = dup(STDOUT_FILENO);
	if (init_fds(NULL, 0) && !*init_fds(NULL, 0))
		handling_redir(root);
	if(root->left->type == EXEC)
	{
		fds = init_fds(NULL, 0);
		tmp = *fds;
		while (fds && *fds)
		{
			if ((*fds)->type == REDIR_IN)
					is_redir_in((*fds)->name[0]);
			else if (((*fds)->type == REDIR_OUT || (*fds)->type == REDIR_APPEND))
					is_redir_out((*fds)->name[0], (*fds)->type);
			*fds = (*fds)->next;
		}
		free_list(&tmp);
	}
	starting_exec(root->left);
	dup_and_close(std_fd);
}
