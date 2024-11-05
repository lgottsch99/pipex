/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:55:45 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:40:22 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"


// t_list	*ft_lstlast(t_list *lst)
// {
// 	t_list	*tmp;

// 	if (!lst)
// 		return (NULL);
// 	tmp = lst;
// 	while (tmp -> next)
// 		tmp = tmp -> next;
// 	return (tmp);
// }

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last -> next = new;
		}
		else
			*lst = new;
	}
}

//checking if elements in list already existing
// only adding element if we have ptr to list 

// #include <stdio.h>
// int main (void)
// {
// 	t_list new;
// 	new.content = "!";
// 	new.next = NULL;//random to see if NULL after ft
// 	t_list l2;
// 	l2.content = "World ";
// 	l2.next = NULL;
// 	t_list l1; 
// 	l1.content = "Hello ";
// 	l1.next =  &l2;

// 	t_list	*ptr = &l1;
// 	t_list	*neww = &new;

// 	ft_lstadd_back(&ptr, neww);
// 	printf("adress node 1: %p\n", &l1);
// 	printf("next in node 1: %p\n", (void *)l1.next);

// 	printf("adress node 2: %p\n", &l2);
// 	printf("next in node 2: %p\n", (void *)l2.next);

// 	printf("adress node 3: %p\n", &new);
// 	printf("next in node 3: %p\n", (void *)new.next);
// }