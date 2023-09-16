/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:25:02 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 14:03:24 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

int	ft_verif_if_is_number_bis(char **tab)
{
	int	i;
	int	j;

	i = 0;
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

int	ft_verif_if_is_int_bis(char **tab)
{
	int				i;
	int				j;
	long long int	valeur;

	valeur = 0;
	i = 0;
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

int	ft_verif_if_is_doublon_bis(char **tab, int taille)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
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

int	ft_verif_if_is_totale_bis(char **tab)
{
	int	verification;
	int	i;

	i = 0;
	verification = 0;
	tab = ft_split(tab[1], ' ');
	while (tab[i])
		i++;
	verification += ft_verif_if_is_number_bis(tab);
	verification += ft_verif_if_is_int_bis(tab);
	verification += ft_verif_if_is_doublon_bis(tab, i);
	ft_free_malloc(tab, i);
	return (verification);
}
