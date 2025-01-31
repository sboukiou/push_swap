/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:08:52 by sboukiou          #+#    #+#             */
/*   Updated: 2024/10/23 18:11:55 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
	* ft_strncmp - compares the first n bytes of the two strings s1 and s2
	* @s1: String 1
	* @s2: String 2
	* @n: Number of initial bytes to compare
	* Return: An integer less than , equal or greater than 0
	* according to the strings comparing
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	count;

	if (!s1 && !s2)
		return (0);
	count = 0;
	while (count < n && (s1[count] || s2[count]))
	{
		if (s1[count] != s2[count])
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		count++;
	}
	return (0);
}
