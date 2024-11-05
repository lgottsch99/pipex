/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:15:19 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:41:33 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

/*
 The memset() function fills the first n bytes of the 
 memory area pointed to by s with the constant byte c.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*tmp = c;
		tmp++;
		i++;
	}
	return (s);
}
// #include <stdio.h>
// int main (void)
// {
//     char string[7] = "Hello!";
//     printf("old: %s\n", string);
//     ft_memset(string, 65, 20);
//     printf("new: %s\n", string);
// }