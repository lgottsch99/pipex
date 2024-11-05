/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:56:43 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/02 14:41:46 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	array[10];
	int		i;
	long	num;

	num = n;
	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		num = num * (-1);
	}
	i = 0;
	while (num)
	{
		array[i++] = (num % 10) + 48;
		num = num / 10;
	}
	while (i-- > 0)
		ft_putchar_fd(array[i], fd);
}

// int main (void)
// {
// 	int x =  -4865;
// 	ft_putnbr_fd(x, 1);
// 	write(1, "\n", 1);
// }