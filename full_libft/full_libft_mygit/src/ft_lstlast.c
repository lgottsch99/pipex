/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:45:10 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:40:57 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"


t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp -> next)
		tmp = tmp -> next;
	return (tmp);
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
// 	t_list	*last = ft_lstlast(ptr);

// 	printf("%s\n", (char *)last -> content);
// }