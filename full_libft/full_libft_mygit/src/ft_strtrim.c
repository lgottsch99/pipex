/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:25:09 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:42:47 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

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
// }
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*tmp;
// 	char			*sub;
// 	unsigned int	i;

// 	if (!s)
// 		return (NULL);
// 	if (start > ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s) - start)
// 		len = ft_strlen(s) - start;
// 	sub = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!sub)
// 		return (NULL);
// 	tmp = (char *)s;
// 	i = 0;
// 	while (i < len)
// 		sub[i++] = tmp[start++];
// 	sub[i] = '\0';
// 	return (sub);
// }

static int	ft_isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	start = (char *)s1;
	end = start + ft_strlen(s1);
	while (ft_isinset(*start, set))
		start++;
	while (ft_isinset(*(end - 1), set) && start < end)
		end--;
	new = ft_substr(start, 0, end - start);
	return (new);
}

// #include <stdio.h>
// int main (void)
// {
// 	char	*s = "aahibbb";
// 	char *set = "ab";
// 	char *trim = ft_strtrim(s, set);
// 	printf("%s\n", trim);
// }