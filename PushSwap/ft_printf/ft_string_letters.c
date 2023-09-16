/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_letters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:49:28 by mthea             #+#    #+#             */
/*   Updated: 2022/11/26 11:36:28 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c, int *verification)
{
	int	number;

	number = 1 ;
	if (*verification != -1)
		number = write(1, &c, 1);
	if (number == -1)
		*verification = -1;
	return (number);
}

int	ft_printf_s(char *s, int *verification)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_printf_s("(null)", verification);
		return (6);
	}
	while (s[i])
	{
		ft_printf_c(s[i], verification);
		i++;
	}
	return (i);
}
