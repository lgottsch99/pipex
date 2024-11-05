/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:52:34 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:42:18 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ls;
	size_t	ld;
	size_t	i;

	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	if (size <= ld)
		return (size + ls);
	i = 0;
	while (i < (size - ld - 1) && src[i])
	{
		dst[ld + i] = src[i];
		i++;
	}
	dst[ld + i] = '\0';
	return (ls + ld);
}

// #include <stdio.h>
// int main (void)
// {
//     char *src = " World";
//     char dst[20]= "Hello";
//     size_t length= ft_strlcat(dst, src, 8);
//     printf("my l: %zu, dst: %s\n", length, dst);

// }