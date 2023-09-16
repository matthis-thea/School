/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:25:02 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 13:55:22 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

int	ft_verif_if_is_number(char **tab)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == 45 && (tab[i][j + 1] > 47
			&& tab[i][j + 1] < 58) && j == 0)
				j++;
			if (tab[i][j] == 43 && (tab[i][j + 1] > 47
			&& tab[i][j + 1] < 58) && j == 0)
				j++;
			if (tab[i][j] < 48 || tab[i][j] > 57)
				return (0);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

long long int	ft_atoi(char *thestring)
{
	long long int	i;
	long long int	valeur;
	int				moins;

	i = 0;
	valeur = 0;
	moins = 0;
	while ((thestring[i] >= 9 && thestring[i] <= 13) || thestring[i] == 32)
		i++;
	if (thestring[i] == 43 || thestring[i] == 45)
	{
		if (thestring[i] == 45)
			moins++;
		i++;
	}
	while (thestring[i] && (thestring[i] >= 48 && thestring[i] <= 57))
	{
		valeur = ((valeur * 10) + (thestring[i] - 48));
		i++;
	}
	if (moins)
		valeur = -valeur;
	if (!(thestring[i] >= 48 && thestring[i] <= 57) && valeur == 0)
		return (0);
	return (valeur);
}

int	ft_verif_if_is_int(char **tab)
{
	int				i;
	int				j;
	long long int	valeur;

	valeur = 0;
	i = 1;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			valeur = ft_atoi(tab[i]);
			j++;
		}
		if (valeur > 2147483647 || valeur < -2147483648)
			return (0);
		valeur = 0;
		j = 0;
		i++;
	}
	return (1);
}

int	ft_verif_if_is_doublon(char **tab, int taille)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < taille)
	{
		while (j < taille)
		{
			if ((ft_atoi(tab[i]) == ft_atoi(tab[j])))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_verif_if_is_totale(char **tab, int taille)
{
	int	verification;

	verification = 0;
	if (taille == 2)
		verification = ft_verif_if_is_totale_bis(tab);
	else
	{
		verification += ft_verif_if_is_number(tab);
		verification += ft_verif_if_is_int(tab);
		verification += ft_verif_if_is_doublon(tab, taille);
	}
	if (verification < 3)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}
