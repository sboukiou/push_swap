/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 00:58:31 by sboukiou          #+#    #+#             */
/*   Updated: 2024/10/25 01:05:00 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*buff;
	size_t	len;

	len = ft_strlen(str);
	buff = (char *)malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	ft_strlcpy(buff, str, len + 1);
	return (buff);
}
