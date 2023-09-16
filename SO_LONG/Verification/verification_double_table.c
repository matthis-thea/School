/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_double_table.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:22:56 by mthea             #+#    #+#             */
/*   Updated: 2023/01/28 14:24:42 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

int	ft_verification_start_exit(char **string)
{
	int		i;
	int		j;
	int		compteur;

	compteur = 0;
	i = 0;
	j = 0;
	while (string[i])
	{
		while (string[i][j])
		{
			if (string[i][j] == 'P')
				compteur++;
			if (string[i][j] == 'E')
				compteur = compteur + 6;
			j++;
		}
		i++;
		j = 0;
	}
	if (compteur == 7)
		return (1);
	ft_printf("Error\nAn exit or an entrance is missing !\n");
	return (0);
}

int	ft_verification_items(char **string)
{
	int		i;
	int		j;
	int		compteur;

	compteur = 0;
	i = 0;
	j = 0;
	while (string[i])
	{
		while (string[i][j])
		{
			if (string[i][j] == 'C')
				compteur++;
			j++;
		}
		i++;
		j = 0;
	}
	if (compteur)
		return (compteur);
	ft_printf("Error\nItems are missing !\n");
	return (0);
}

int	ft_verification_wall(char **string)
{
	int		i;
	int		j;
	int		min;
	int		max;

	min = ft_number_columns(string) - 2;
	max = ft_number_lines(string) - 1;
	i = 0;
	j = 0;
	while (string[i])
	{
		while (string[i][j] != '\n')
		{
			if (string[0][j] != '1' || string[max][j] != '1')
				return (0);
			if (string[i][0] != '1' || string[i][min] != '1')
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ft_verification_rectangular(char **string)
{
	int		i;
	int		j;
	int		first_compteur;
	int		second_verif;

	i = 0;
	j = 0;
	while (string[i])
	{
		while (string[i][j])
		{
			j++;
		}
		if (i == 0 && j > 0)
			first_compteur = j;
		second_verif = j;
		if ((first_compteur != second_verif))
			return (0);
		i++;
		j = 0;
	}
	if (i < 3)
		return (0);
	return (1);
}

int	ft_verification_totale(char **string)
{
	int	verification;

	verification = ft_verification_start_exit(string);
	if (verification == 0)
		return (0);
	verification = ft_verification_items(string);
	if (verification == 0)
		return (0);
	verification = ft_verification_wall(string);
	if (verification == 0)
	{
		ft_printf("Error\nWalls is missing !\n");
		return (0);
	}
	verification = ft_verification_rectangular(string);
	if (verification == 0)
	{
		ft_printf("Error\nThe map is not rectangular!\n");
		return (0);
	}
	verification = ft_verification_items_letters(string);
	if (verification == 0)
		return (0);
	return (1);
}
