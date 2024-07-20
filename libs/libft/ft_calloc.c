/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etovaz <egeraldo@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:21:30 by egeraldo          #+#    #+#             */
/*   Updated: 2024/07/20 19:27:39 by etovaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*alloc;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb == 0 || size == 0 || (total_size / size != nmemb))
		return (malloc(0));
	alloc = malloc(total_size);
	if (alloc != NULL)
		while (total_size)
			alloc[--total_size] = 0;
	return ((void *)alloc);
}
