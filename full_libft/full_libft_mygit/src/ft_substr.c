/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:00:07 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:42:51 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"
/*
Allocates (with malloc(3)) and returns a substring
from the string ’s’.
The substring begins at index ’start’ and is of
maximum size ’len’.

returns The substring or NULL if the allocation fails.
*/

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(const char *s1)
// {
// 	char	*ptr;
// 	int		len;
// 	int		i;

// 	len = ft_strlen(s1) + 1;
// 	ptr = (char *)malloc(sizeof(char) * len);
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		ptr[i] = (char)s1[i];
// 		i++;
// 	}
// 	return (ptr);
//}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tmp;
	char			*sub;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	tmp = (char *)s;
	i = 0;
	while (i < len)
		sub[i++] = tmp[start++];
	sub[i] = '\0';
	return (sub);
}

// #include <stdio.h>
// int main (void)
// {
// 	char *s = "Hello World this is sick lilli.";
// 	size_t	len = 205;
// 	int	index = 6; //we start indexing at 0!

// 	char *sub = ft_substr(s, index, len);
// 	printf("%s\n", sub);
// }