/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_verif_elements_solo.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:11:00 by haze              #+#    #+#             */
/*   Updated: 2023/10/27 22:47:47 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	ft_verif_north(char **map, t_verification *pars, char *argv)
{
	if (map[pars->i][pars->j] == 'N'
		&& map[pars->i][pars->j + 1] == 'O'
		&& pars->tab_gestion[0] == 0)
	{
		pars->j += 2;
		while (map[pars->i][pars->j] == 32 || map[pars->i][pars->j] == 9)
			(pars->j)++;
		if (map[pars->i][pars->j + 1])
			pars->north_texture = ft_strdup_bis(&map[pars->i][pars->j]);
		pars->tab_gestion[0] = 1;
	}
	else if (map[pars->i][pars->j] == 'N'
		&& map[pars->i][pars->j + 1] == 'O'
		&& pars->tab_gestion[0] == 1)
	{
		ft_error_return(-3, pars, argv, 3);
	}
}

void	ft_verif_south(char **map, t_verification *pars, char *argv)
{
	if (map[pars->i][pars->j] == 'S'
		&& map[pars->i][pars->j + 1] == 'O'
		&& pars->tab_gestion[1] == 0)
	{
		pars->j += 2;
		while (map[pars->i][pars->j] == 32 || map[pars->i][pars->j] == 9)
			(pars->j)++;
		if (map[pars->i][pars->j + 1])
			pars->south_texture = ft_strdup_bis(&map[pars->i][pars->j]);
		pars->tab_gestion[1] = 1;
	}
	else if (map[pars->i][pars->j] == 'S'
		&& map[pars->i][pars->j + 1] == 'O'
		&& pars->tab_gestion[1] == 1)
	{
		ft_error_return(-3, pars, argv, 3);
	}
}

void	ft_verif_east(char **map, t_verification *pars, char *argv)
{
	if (map[pars->i][pars->j] == 'E'
		&& map[pars->i][pars->j + 1] == 'A'
		&& pars->tab_gestion[2] == 0)
	{
		pars->j += 2;
		while (map[pars->i][pars->j] == 32 || map[pars->i][pars->j] == 9)
			(pars->j)++;
		if (map[pars->i][pars->j + 1])
			pars->east_texture = ft_strdup_bis(&map[pars->i][pars->j]);
		pars->tab_gestion[2] = 1;
	}
	else if (map[pars->i][pars->j] == 'E'
		&& map[pars->i][pars->j + 1] == 'A'
		&& pars->tab_gestion[2] == 1)
	{
		ft_error_return(-3, pars, argv, 3);
	}
}

void	ft_verif_west(char **map, t_verification *pars, char *argv)
{
	if (map[pars->i][pars->j] == 'W'
		&& map[pars->i][pars->j + 1] == 'E'
		&& pars->tab_gestion[3] == 0)
	{
		pars->j += 2;
		while (map[pars->i][pars->j] == 32 || map[pars->i][pars->j] == 9)
			(pars->j)++;
		if (map[pars->i][pars->j + 1])
			pars->west_texture = ft_strdup_bis(&map[pars->i][pars->j]);
		pars->tab_gestion[3] = 1;
	}
	else if (map[pars->i][pars->j] == 'W'
		&& map[pars->i][pars->j + 1] == 'E'
		&& pars->tab_gestion[3] == 1)
	{
		ft_error_return(-3, pars, argv, 3);
	}
}

void	ft_verif_floor(char **map, t_verification *pars, char *argv)
{
	pars->d = 0;
	pars->z = 0;
	if (map[pars->i][pars->j] == 'F'
		&& map[pars->i][pars->j + 1] == ' '
		&& pars->tab_gestion[4] == 0)
	{
		ft_verif_floor_bis(map, pars, argv);
		pars->tab_gestion[4] = 1;
	}
	else if (map[pars->i][pars->j] == 'F'
	&& map[pars->i][pars->j + 1] == ' '
	&& pars->tab_gestion[4] == 1)
	{
		ft_error_return(-3, pars, argv, 3);
	}
}
