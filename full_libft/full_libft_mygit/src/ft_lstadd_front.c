/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:25:20 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:40:27 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"


// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*tmp;

// 	tmp = (t_list *)malloc(sizeof(t_list));
// 	if (!tmp)
// 		return (NULL);
// 	tmp -> content = content;
// 	tmp -> next = NULL;
// 	return (tmp);
// }

/*
Adds the node ’new’ at the beginning of the list.

lst is ptr to first element of list
*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	new -> next = *lst;
	*lst = new;
}

// #include <stdio.h>
// int main (void)
// {
// 	t_list l2;
// 	l2.content = "!";
// 	l2.next = NULL;
// 	t_list l1; 
// 	l1.content = "World ";
// 	l1.next =  &l2;

// 	t_list	*ptr = &l2; //if this NULL then new is first
// 	t_list	*new = ft_lstnew("Hello");

// 	ft_lstadd_front(&ptr, new);

// 	printf("%p = mem adress l2\n", &l2);
// 	printf("%p = new.next\n", new -> next);
// }