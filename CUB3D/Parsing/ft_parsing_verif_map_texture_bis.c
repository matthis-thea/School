/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_verif_map_texture_bis.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:43:05 by haze              #+#    #+#             */
/*   Updated: 2023/10/31 13:53:57 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	reinitiliasation_map_bis(t_verification *pars)
{
	pars->i = 0;
	pars->j = 0;
	while (pars->binary_map[pars->i])
	{
		while (pars->binary_map[pars->i][pars->j])
		{
			(pars->j)++;
		}
		if (pars->j < pars->size_map_x)
		{
			while (pars->j < pars->size_map_x)
			{
				pars->binary_map[pars->i][pars->j] = '1';
				(pars->j)++;
			}
		}
		pars->binary_map[pars->i][pars->j] = '\0';
		(pars->i)++;
		pars->j = 0;
	}
}

void	reinitialisation_map(t_verification *pars)
{
	pars->i = 0;
	pars->j = 0;
	while (pars->binary_map[pars->i])
	{
		while (pars->binary_map[pars->i][pars->j])
		{
			if (pars->binary_map[pars->i][pars->j] == 'X')
			{
				if (pars->i == pars->player_y && pars->j == pars->player_x)
					pars->binary_map[pars->i][pars->j] = pars->orientation;
				else
					pars->binary_map[pars->i][pars->j] = '0';
			}
			else if (pars->binary_map[pars->i][pars->j] == '\n')
				pars->binary_map[pars->i][pars->j] = '\n';
			else if (pars->binary_map[pars->i][pars->j] == ' ')
				pars->binary_map[pars->i][pars->j] = '1';
			(pars->j)++;
		}
		(pars->i)++;
		pars->j = 0;
	}
	reinitiliasation_map_bis(pars);
}
