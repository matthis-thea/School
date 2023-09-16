/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:06:11 by mthea             #+#    #+#             */
/*   Updated: 2022/08/01 10:24:49 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putnbr(int nb)
{
	char	characteres;
	int		b;

	b = 0;
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		nb = -(nb + ++b);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	characteres = '0' + nb % 10;
	nb = nb / 10;
	if (nb != 0)
		ft_putnbr(nb);
	if (b == 1)
		characteres++;
	write(1, &characteres, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
