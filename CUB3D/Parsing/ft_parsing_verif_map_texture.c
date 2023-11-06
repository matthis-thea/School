/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_verif_map_texture.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:43:05 by haze              #+#    #+#             */
/*   Updated: 2023/10/30 11:07:58 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	ft_verif_map_elements_bis(char **map, t_verification *pars, char *argv)
{
	if ((map[pars->i][pars->j] == '0' || map[pars->i][pars->j] == '1'
		|| map[pars->i][pars->j] == ' ' || map[pars->i][pars->j] == 'W'
		|| map[pars->i][pars->j] == 'S' || map[pars->i][pars->j] == 'E'
		|| map[pars->i][pars->j] == 'N'
		|| map[pars->i][pars->j] == '\n')
		&& map[pars->i][pars->j])
	{
		if (map[pars->i][pars->j] == 'W'
			|| map[pars->i][pars->j] == 'S'
			|| map[pars->i][pars->j] == 'E'
			|| map[pars->i][pars->j] == 'N')
		{
			if (pars->boolean == 0)
				ft_error_return(-6, pars, argv, 3);
			pars->boolean = 0;
		}
		(pars->j)++;
	}
	else
		ft_error_return(-7, pars, argv, 3);
}

void	ft_verif_map_elements(char **map, t_verification *pars, char *argv)
{
	pars->j = 0;
	pars->i = 0;
	pars->boolean = 1;
	while (map[pars->i])
	{
		while (map[pars->i][pars->j])
		{
			ft_verif_map_elements_bis(map, pars, argv);
		}
		(pars->i)++;
		pars->j = 0;
	}
	if (pars->boolean)
		ft_error_return(-7, pars, argv, 3);
}

void	verif_map_compact(char **map, t_verification *pars, char *argv)
{
	pars->j = 0;
	pars->i = 0;
	pars->boolean = 0;
	while (map[pars->i])
	{
		while (map[pars->i][pars->j])
		{
			if (map[pars->i][pars->j] == 32 || map[pars->i][pars->j] == 9)
				pars->boolean = 1;
			else
				pars->boolean = 0;
			(pars->j)++;
		}
		if (pars->j == 0)
			pars->boolean = 1;
		(pars->i)++;
		pars->j = 0;
	}
	if (pars->boolean)
		ft_error_return(-7, pars, argv, 3);
}

void	positon_player(t_verification *pars)
{
	pars->i = 0;
	pars->j = 0;
	while (pars->binary_map[pars->i])
	{
		while (pars->binary_map[pars->i][pars->j])
		{
			if ((pars->binary_map[pars->i][pars->j] == 'W'
				|| pars->binary_map[pars->i][pars->j] == 'S'
				|| pars->binary_map[pars->i][pars->j] == 'E'
				|| pars->binary_map[pars->i][pars->j] == 'N'))
			{
				pars->orientation = pars->binary_map[pars->i][pars->j];
				pars->player_x = pars->j;
				pars->player_y = pars->i;
			}
			(pars->j)++;
		}
		(pars->i)++;
		pars->j = 0;
	}
}

void	ft_verif_texture(t_verification *pars, char *argv)
{
	pars->texture = mlx_load_png(pars->north_texture);
	if (!pars->texture)
	{
		ft_error_return(50, pars, argv, 3);
	}
	mlx_delete_texture(pars->texture);
	pars->texture = mlx_load_png(pars->south_texture);
	if (!pars->texture)
	{
		ft_error_return(50, pars, argv, 3);
	}
	mlx_delete_texture(pars->texture);
	pars->texture = mlx_load_png(pars->east_texture);
	if (!pars->texture)
	{
		ft_error_return(50, pars, argv, 3);
	}
	mlx_delete_texture(pars->texture);
	pars->texture = mlx_load_png(pars->west_texture);
	if (!pars->texture)
	{
		ft_error_return(50, pars, argv, 3);
	}
	mlx_delete_texture(pars->texture);
}
