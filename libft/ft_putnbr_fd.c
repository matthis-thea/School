/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:55:51 by mthea             #+#    #+#             */
/*   Updated: 2022/11/15 14:52:21 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	characteres;
	int		b;

	b = 0;
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		n = -(n + ++b);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	characteres = '0' + n % 10;
	n = n / 10;
	if (n != 0)
		ft_putnbr_fd(n, fd);
	if (b == 1)
		characteres++;
	write(fd, &characteres, 1);
}
