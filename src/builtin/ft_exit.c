/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:27:31 by etovaz            #+#    #+#             */
/*   Updated: 2024/03/20 11:03:52 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	ft_intlen(long long n)
{
	int	len;

	if (n < 0)
		n = -n;
	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_splitlen(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

int	print_error_exit(char *tmp, int flag)
{
	if (flag == 2)
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(tmp, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		update_status_error(2);
		return (1);
	}
	if (flag == 1)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		update_status_error(1);
		return (0);
	}
	return (2);
}

int	handle_exit_error(char **prompt)
{
	long long	nb;
	char		*tmp;

	if (!prompt)
		return (1);
	nb = ft_atol(prompt[1]);
	if (prompt[1] && (prompt[1][0] == '+' || prompt[1][0] == '-'))
		tmp = &prompt[1][1];
	else
		tmp = prompt[1];
	if ((tmp && ft_strlen(tmp) != ft_intlen(nb)) || (tmp && !ft_isnum(tmp)))
		return (print_error_exit(tmp, 2));
	if (ft_splitlen(prompt) > 2)
	{
		if (ft_isdigit(prompt[1][0]))
			return (print_error_exit(tmp, 1));
		else
			return (print_error_exit(tmp, 2));
	}
	update_status_error(nb);
	return (1);
}

void	ft_exit(char **prompt, t_ast *root)
{
	int	i;

	if (!prompt)
		ft_putstr_fd("\n", STDERR_FILENO);
	if (handle_exit_error(prompt))
	{
		free_env_list(*create_envs_table(1, 1));
		save_fds(NULL, 1);
		ast_holder(root, 1, 1);
		if (!on_heredoc(-1))
			ft_putstr_fd("exit\n", STDERR_FILENO);
		i = 0;
		while (i < 3)
			close(i++);
		rl_clear_history();
		exit(update_status_error(-1));
	}
	ft_putendl_fd("exit", STDERR_FILENO);
	return ;
}
