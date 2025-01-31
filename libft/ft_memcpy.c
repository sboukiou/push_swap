/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:13:19 by sboukiou          #+#    #+#             */
/*   Updated: 2024/10/22 18:24:20 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				size;
	unsigned char		*srcstr;
	unsigned char		*deststr;

	if ((!dest && !src) || dest == src)
		return (dest);
	size = 0;
	srcstr = (unsigned char *)src;
	deststr = (unsigned char *)dest;
	while (size < n)
	{
		deststr[size] = srcstr[size];
		size++;
	}
	return (dest);
}
