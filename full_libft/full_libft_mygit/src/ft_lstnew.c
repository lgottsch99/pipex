/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:07:21 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:41:03 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

// #include <stdlib.h>
// typedef struct	s_list
// {
// 	void	*content;
// 	struct	s_list	*next;
// }	t_list;
/*
Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp -> content = content;
	tmp -> next = NULL;
	return (tmp);
}

// #include <stdio.h>
// int main (void)
// {
// 	t_list *ptr;
// 	ptr = ft_lstnew("Hello.");
// 	printf("%s\n", (char *)ptr -> content);
// 	printf("%s\n", (char *)ptr-> next);
// }
