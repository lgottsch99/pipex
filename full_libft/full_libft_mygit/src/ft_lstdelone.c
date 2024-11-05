/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:14:02 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:40:49 by lgottsch         ###   ########.fr       */
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

// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	len;

// 	len = ft_strlen(src);
// 	if (size == 0)
// 		return (len);
// 	i = 0;
// 	while (i < (size - 1) && src[i] != '\0')
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (len);
// }

// //sample ft
// void	delete(void	*ptr)
// {
// 	free(ptr);
// }

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst -> content);
		free(lst);
	}
}
//list should stay intact bc next is still there?

// #include <stdlib.h>
// #include <stdio.h>
// int main(void)
// {
// 	//t_list	*ptr;
// 	t_list	*one = (t_list *)malloc(sizeof(t_list));

// 	one -> content = malloc (sizeof(char) * 10);

// 	size_t a = ft_strlcpy(one -> content, "Hi", 10);
// 	a = 0;

// 	printf("content before deletion: %s\n", (char *)one -> content);
// 	printf("next before deletion: %p\n", one -> next);

// 	ft_lstdelone(one, delete);

// 	if (one -> content)
// 		printf("content after deletion: %s\n", (char *)one -> content);
// 	printf("next after deletion: %p\n", one -> next);

// }