/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:29:37 by mthea             #+#    #+#             */
/*   Updated: 2022/11/26 11:49:20 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_void(unsigned long long nb, int *verification)
{
	int					resultat;
	char				*str;
	int					i;
	char				*base;

	base = "0123456789abcdef";
	i = ft_count_return_nb_long(nb);
	resultat = 0;
	str = NULL;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (verification_null(verification));
	str[i] = 0;
	str[0] = '0';
	str[1] = 'x';
	while (i > 2)
	{
		resultat = nb % 16;
		nb = nb / 16;
		str[--i] = base[resultat];
	}
	i = ft_printf_s(str, verification);
	free(str);
	return (i);
}
