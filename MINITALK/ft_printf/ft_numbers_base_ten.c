/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_base_ten.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:29:09 by mthea             #+#    #+#             */
/*   Updated: 2022/11/26 11:36:18 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nb(int n, int *verification)
{
	char	characteres;
	int		value_return;
	int		b;

	b = 0;
	value_return = ft_count_return_nb(n);
	if (n == -2147483647 - 1)
	{
		ft_printf_s("-2147483648", verification);
		return (11);
	}
	else if (n < 0)
	{
		ft_printf_c('-', verification);
		n = -n;
		b = 1;
	}
	characteres = '0' + n % 10;
	n = n / 10;
	if (n != 0)
		ft_printf_nb(n, verification);
	ft_printf_c(characteres, verification);
	if (b == 1)
		return (value_return + 1);
	return (value_return);
}

int	ft_printf_nb_u(unsigned int n, int *verification)
{
	char	characteres;
	int		value_return;

	value_return = ft_count_return_nb_u(n);
	characteres = '0' + n % 10;
	n = n / 10;
	if (n != 0)
		ft_printf_nb_u(n, verification);
	ft_printf_c(characteres, verification);
	return (value_return);
}
