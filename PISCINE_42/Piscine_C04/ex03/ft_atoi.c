/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:49:41 by mthea             #+#    #+#             */
/*   Updated: 2022/07/20 16:32:29 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	compteur(char *str)
{
	int	i;
	int	compteurmoins;
	int	nombre;

	i = 0;
	compteurmoins = 0;
	nombre = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			compteurmoins++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nombre = ((nombre * 10) + (str[i] - 48));
		i++;
	}
	if ((compteurmoins % 2) != 0)
		nombre = -nombre;
	return (nombre);
}

int	ft_atoi(char *str)
{	
	int	nombre;
	int	i;

	nombre = 0;
	i = 0;
	if ((str[0] >= 9 && str[0] <= 13) || str[0] == 32
		|| str[0] == '-' || str[0] == '+')
	{
		nombre = compteur(str);
	}
	else
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			nombre = ((nombre * 10) + (str[i] - 48));
			i++;
		}	
	}
	return (nombre);
}
