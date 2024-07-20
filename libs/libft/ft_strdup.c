/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:22:21 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/20 19:25:40 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	int		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	new = ft_calloc(len + 1, sizeof(char));
	if (!new)
		return (0);
	len = -1;
	while (src && src[++len])
		new[len] = src[len];
	new[len] = '\0';
	return (new);
}
