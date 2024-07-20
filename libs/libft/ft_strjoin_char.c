/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:51:03 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/20 19:26:44 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_char(char *str, char c)
{
	char	concat[2];

	concat[0] = c;
	concat[1] = '\0';
	str = ft_strjoin(str, concat, 1);
	return (str);
}
