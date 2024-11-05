/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:31:17 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:41:08 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"


int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = lst;
	if (lst)
	{
		len = 1;
		while (!(tmp -> next == NULL))
		{
			tmp = tmp -> next;
			len++;
		}
	}
	return (len);
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

// 	int len = ft_lstsize(ptr);

// 	printf("len: %i\n", len);
// }