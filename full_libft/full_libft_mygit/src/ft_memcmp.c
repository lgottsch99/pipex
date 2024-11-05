/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:04:13 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:41:20 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"


int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		x;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			x = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
			return (x);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main (void)
// {
//     char *s1 = "Hello World";
//     char *s2 = "Hello";

//     int x = ft_memcmp(s1, s2, 0);
//     printf("x: %i\n", x);
// }