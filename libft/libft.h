/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukiou <sboukiou@1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:04:31 by sboukiou          #+#    #+#             */
/*   Updated: 2025/01/29 18:53:25 by sboukiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*Includes - unistd + stdlib for malloc , read & write*/
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/*Structures*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*Functions prototypes*/
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);
long	ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(const char *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_double_free(char **list);
#endif
