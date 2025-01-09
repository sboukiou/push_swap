/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:21:21 by sboukiou          #+#    #+#             */
/*   Updated: 2024/10/22 16:35:54 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			size;
	unsigned char	*buff;

	if (n == 0)
		return (s);
	buff = (unsigned char *)s;
	size = 0;
	while (size < n)
	{
		buff[size] = (unsigned char)c;
		size++;
	}
	return (s);
}
