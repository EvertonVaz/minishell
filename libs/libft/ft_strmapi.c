/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:44:18 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/20 19:25:40 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;
	size_t			len;

	if (s == NULL)
		return (NULL);
	mapi = (char *)ft_calloc((len = ft_strlen(s)) + 1, sizeof(char));
	if (mapi == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		mapi[i] = f(i, s[i]);
	return (mapi);
}
