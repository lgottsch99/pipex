/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:56:51 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:42:38 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;

	if (ft_strlen(little) == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			y = 0;
			while (big[i + y] == little[y] && i + y < len)
			{
				if (little[y + 1] == '\0')
					return ((char *)&big[i]);
				y++;
			}
		}
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	char * big = "Foo Bar Baz";
// 	char *little = "v";
// 	char* r = ft_strnstr(big, little, 7);
// 	printf("%s\n", r);
// }