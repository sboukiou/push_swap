/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:16:43 by sboukiou          #+#    #+#             */
/*   Updated: 2024/10/23 18:19:50 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned char	*s1str;
	unsigned char	*s2str;
	unsigned int	count;

	if (!s1 && !s2)
		return (0);
	s1str = (unsigned char *)s1;
	s2str = (unsigned char *)s2;
	count = 0;
	while (count < n)
	{
		if (s1str[count] != s2str[count])
			return (s1str[count] - s2str[count]);
		count++;
	}
	return (0);
}
