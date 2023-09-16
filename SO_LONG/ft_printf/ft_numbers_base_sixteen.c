/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_base_sixteen.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:29:27 by mthea             #+#    #+#             */
/*   Updated: 2022/11/26 11:41:58 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nb_x(unsigned int nbr, int *verification)
{
	int					resultat;
	char				*str;
	int					i;
	char				*base;

	base = "0123456789abcdef";
	i = ft_count_return_nb_x(nbr);
	resultat = 0;
	str = NULL;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (verification_null(verification));
	str[i] = 0;
	while (i > 0)
	{
		resultat = nbr % 16;
		nbr = nbr / 16;
		str[--i] = base[resultat];
	}
	i = ft_printf_s(str, verification);
	free(str);
	return (i);
}

int	ft_printf_nb_big_x(unsigned int nbr, int *verification)
{
	int					resultat;
	char				*str;
	int					i;
	char				*base;

	base = "0123456789ABCDEF";
	i = ft_count_return_nb_x(nbr);
	resultat = 0;
	str = NULL;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (verification_null(verification));
	str[i] = 0;
	while (i > 0)
	{
		resultat = nbr % 16;
		nbr = nbr / 16;
		str[--i] = base[resultat];
	}
	i = ft_printf_s(str, verification);
	free(str);
	return (i);
}
