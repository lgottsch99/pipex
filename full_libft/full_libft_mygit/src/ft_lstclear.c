/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:59:38 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:40:34 by lgottsch         ###   ########.fr       */
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

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (lst && del)
// 	{
// 		del(lst -> content);
// 		free(lst);
// 	}
// }

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)-> next;
		ft_lstdelone(tmp, del);
	}
	free(*lst);
	*lst = NULL;
}

// #include <stdlib.h>
// #include <stdio.h>
// int main(void)
// {
// 	t_list	*one = (t_list *)malloc(sizeof(t_list));
// 	t_list	*two = (t_list *)malloc(sizeof(t_list));

// 	//malloc space for content
// 	one -> content = malloc (sizeof(char) * 10);
// 	two -> content = malloc (sizeof(char) * 10);

// 	//connect to form list
// 	one -> next = two;

// 	//fill w content
// 	size_t a = ft_strlcpy(one -> content, "Hi", 10);
// 	a = 0;
// 	size_t b = ft_strlcpy(two -> content, "Bye", 10);
// 	b = 0;

// 	printf("content before deletion: %s\n", (char *)one -> content);
// 	printf("next before deletion: %p\n", one -> next);
// 	printf("content before deletion: %s\n", (char *)two -> content);
// 	printf("next before deletion: %p\n", two -> next);

// 	t_list	*ptr;
// 	ptr = one;
// 	ft_lstclear(&ptr, delete);

// 	if (one -> content)
// 		printf("content one after deletion: %s\n", (char *)one -> content);
// 	printf("next after deletion: %p\n", one -> next);
// 	if (two -> content)
// 		printf("content two after deletion: %s\n", (char *)two -> content);
// 	printf("next after deletion: %p\n", two -> next);

// 	if (ptr == NULL) {
//         printf("List has been cleared.\n");
//     }

// }