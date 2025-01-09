/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:03:28 by sboukiou          #+#    #+#             */
/*   Updated: 2024/10/23 18:06:15 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
	* ft_strrchr - returns a pointer to the last occurrence of the character
	* c in the string s
	* @s: String to check
	* @c: Character to find
	* @Return: Address of last occurrence of c or NULL
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*address;
	int		count;

	count = 0;
	address = NULL;
	while (s[count])
	{
		if (s[count] == (unsigned char)c)
			address = (char *)(s + count);
		count++;
	}
	if ((unsigned char)c == 0)
		return ((char *)(s + count));
	return (address);
}
