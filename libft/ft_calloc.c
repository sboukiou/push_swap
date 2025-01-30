/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:11:52 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/29 18:51:50 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*buff;

	if (nmemb && ((nmemb * size) / nmemb) != size)
		return (NULL);
	buff = malloc(nmemb * size);
	if (!buff)
		return (NULL);
	ft_bzero(buff, nmemb * size);
	return (buff);
}

void	ft_double_free(char **list)
{
	int	idx;

	idx = 0;
	while (list[idx])
	{
		free(list[idx]);
		list[idx] = NULL;
		idx++;
	}
	free(list);
	list = NULL;
}

