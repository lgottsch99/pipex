/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:15:17 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:40:54 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"


// #include <stdio.h>
// void	print(void	*ptr)
// {
// 	printf("%s\n", (char *)ptr);
// }

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		f(ptr -> content);
		ptr = ptr -> next;
	}
}

// #include <stdio.h>
// int main (void)
// {
// 	t_list l3;
// 	l3.content = "!";
// 	l3.next = NULL;
// 	t_list l2;
// 	l2.content = "World ";
// 	l2.next = &l3;
// 	t_list l1; 
// 	l1.content = "Hello ";
// 	l1.next =  &l2;

// 	t_list	*ptr = &l1;
// 	ft_lstiter(ptr, print);
// }