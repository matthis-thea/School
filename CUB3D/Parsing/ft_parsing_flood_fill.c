/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_flood_fill.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:40:59 by haze              #+#    #+#             */
/*   Updated: 2023/10/30 11:01:08 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	tab_size_max_y(char **tab, t_verification *pars)
{
	int	i;
	int	j;

	i = pars->i;
	j = pars->j;
	while (tab[i][j])
		j++;
	pars->max_y = j;
}

void	tab_size_max_x(char **tab, t_verification *pars)
{
	int	i;

	i = pars->i;
	while (tab[i])
		i++;
	pars->max_x = i;
}

void	ft_recursive_flood(char **tab, int px, int py, t_verification *pars)
{
	if (px < 0 || py < 0
		|| px >= pars->max_x || py >= pars->max_y
		|| tab[px][py] == ' ')
	{
		ft_error_return(-10, pars, pars->argv, 3);
	}
	if (tab[px][py] == '1' || tab[px][py] == 'X')
		return ;
	tab[px][py] = 'X';
	ft_recursive_flood(tab, px - 1, py, pars);
	ft_recursive_flood(tab, px + 1, py, pars);
	ft_recursive_flood(tab, px, py - 1, pars);
	ft_recursive_flood(tab, px, py + 1, pars);
}

int	ft_verification_flood_fill(t_verification *pars)
{
	pars->i = 0;
	pars->j = 0;
	tab_size_max_x(pars->binary_map, pars);
	while (pars->binary_map[pars->i])
	{
		while (pars->binary_map[pars->i][pars->j])
		{
			if (pars->binary_map[pars->i][pars->j] == '0'
				|| pars->binary_map[pars->i][pars->j] == 'N'
				|| pars->binary_map[pars->i][pars->j] == 'S'
				|| pars->binary_map[pars->i][pars->j] == 'W'
				|| pars->binary_map[pars->i][pars->j] == 'E')
			{
				tab_size_max_y(pars->binary_map, pars);
				pars->h = pars->i;
				pars->z = pars->j;
				ft_recursive_flood(pars->binary_map, pars->h, pars->z, pars);
			}
			(pars->j)++;
		}
		(pars->i)++;
		pars->j = 0;
	}
	return (1);
}
