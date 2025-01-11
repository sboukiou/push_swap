/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:12:44 by sboukiou          #+#    #+#             */
/*   Updated: 2024/10/23 18:16:12 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			count;

	str = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (str[count] == (unsigned char)c)
			return (str + count);
		count++;
	}
	return (NULL);
}
