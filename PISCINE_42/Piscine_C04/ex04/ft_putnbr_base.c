/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:49:41 by mthea             #+#    #+#             */
/*   Updated: 2022/07/29 11:18:57 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	ft_strlength(char *str);
int	ft_error(char *str);

int	ft_strlength(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_error(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (str[i] == 0 || ft_strlength(str) == 1)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		return (0);
	while (i < (ft_strlength(str) - 1))
	{
		while (j < ft_strlength(str))
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				j;
	int				i;
	unsigned int	resultat;
	unsigned int	nombres;

	i = 0;
	resultat = 0;
	j = ft_strlength(base);
	if (ft_error(base) != 0)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nombres = -nbr;
		}
		else
			nombres = nbr;
		resultat = nombres % j;
		nombres = nombres / j;
		if (nombres != 0)
			ft_putnbr_base(nombres, base);
		write(1, &base[resultat], 1);
	}
}
