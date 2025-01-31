/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:58:30 by sboukiou          #+#    #+#             */
/*   Updated: 2024/11/06 16:58:32 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, const char *set)
{
	int	count;

	count = 0;
	while (set[count])
	{
		if (set[count] == c)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_index;
	int		end_index;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	while (s1[start_index] && ft_isset(s1[start_index], set))
		start_index++;
	end_index = ft_strlen(s1);
	while (s1[start_index] && ft_isset(s1[end_index - 1], set))
		end_index--;
	if (start_index > end_index)
		return (NULL);
	trimmed = ft_calloc(end_index - start_index + 1, sizeof(char));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start_index, end_index - start_index + 1);
	return (trimmed);
}
