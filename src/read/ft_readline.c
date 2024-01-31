/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeraldo <egeraldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:37:28 by egeraldo          #+#    #+#             */
/*   Updated: 2024/01/31 17:25:06 by egeraldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_readline(void)
{
	char *buffer;
	char *prompt;

	prompt = malloc(2);
	prompt[0] = '\0';
	prompt = ft_strjoin(prompt, getenv("USER"));
	prompt = ft_strjoin(prompt, "@minishell $>");
	buffer = readline(prompt);
	add_history(buffer);
	free(prompt);
	return (buffer);
}
