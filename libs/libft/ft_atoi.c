/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:31:31 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/20 19:25:10 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str && ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' '))
		i++;
	if (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str && ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}
