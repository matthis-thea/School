/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:36:32 by mthea             #+#    #+#             */
/*   Updated: 2023/01/28 14:08:04 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

int	ft_number_columns(char **string)
{
	int		i;
	int		j;
	int		compteur;

	compteur = 0;
	i = 0;
	j = 0;
	while (string[i][j])
	{
		j++;
	}
	return (j);
}

int	ft_number_lines(char **string)
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
			j++;
		}
		i++;
		j = 0;
	}
	return (i);
}

int	ft_position_p_columns(char **string)
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
				return (j);
			j++;
		}
		i++;
		j = 0;
	}
	return (i);
}

int	ft_position_p_line(char **string)
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
				return (i);
			j++;
		}
		i++;
		j = 0;
	}
	return (i);
}
