/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:51:45 by mthea             #+#    #+#             */
/*   Updated: 2022/07/14 10:55:16 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	ft_print_comb2(void)
{
	int		nb2;
	int		nb1;
	int		resultat;

	nb2 = 1;
	nb1 = 0;
	while (nb1 <= 98)
	{
		while (nb2 <= 99)
		{
			resultat = nb1 / 10 + '0';
			write(1, &resultat, 1);
			resultat = nb1 % 10 + '0';
			write(1, &resultat, 1);
			write(1, " ", 1);
			resultat = nb2 / 10 + '0';
			write(1, &resultat, 1);
			resultat = nb2 % 10 + '0';
			write(1, &resultat, 1);
			if (!(nb1 == 98))
				write(1, &", ", 2);
			nb2++;
		}
	nb2 = ++nb1 + 1;
	}
}
