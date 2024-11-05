/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:48:07 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:42:05 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = (char)s1[i];
		i++;
	}
	return (ptr);
}

// /in loop: len includes nul, so it should be copied as well
// #include <stdio.h>
// int main (void)
// {
// 	char *s1 = "";
// 	char *ptr;
// 	ptr = ft_strdup(s1);
// 	printf("%s\n", ptr);
// }