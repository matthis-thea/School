/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_verif_elements_solo_bis.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:22:49 by haze              #+#    #+#             */
/*   Updated: 2023/10/28 14:33:48 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

int	ft_verif_floor_bis(char **map, t_verification *pars, char *argv)
{
	pars->z = 0;
	pars->h = 0;
	(pars->j)++;
	pars->color = ft_split(&map[pars->i][pars->j], ',');
	if (!pars->color)
		return (ft_error_return(-11, pars, argv, 3));
	while (pars->color[pars->h])
		(pars->h)++;
	while (pars->z < pars->h)
	{
		if (ft_atoi(pars->color[pars->z]) < 0 || pars->h != 3
			|| ft_isdigit_str(pars->color[pars->z]) == 0)
		{
			ft_free_split(pars->color, pars->h);
			ft_error_return(-4, pars, argv, 3);
		}
		(pars->z)++;
	}
	pars->red_floor = ft_atoi(pars->color[0]);
	pars->green_floor = ft_atoi(pars->color[1]);
	pars->blue_floor = ft_atoi(pars->color[2]);
	ft_free_split(pars->color, pars->h);
	return (1);
}

int	ft_verif_ceiling_bis(char **map, t_verification *pars, char *argv)
{
	pars->z = 0;
	pars->h = 0;
	(pars->j)++;
	pars->color = ft_split(&map[pars->i][pars->j], ',');
	if (!pars->color)
		return (ft_error_return(-11, pars, argv, 3));
	while (pars->color[pars->h])
		(pars->h)++;
	while (pars->z < pars->h)
	{
		if (ft_atoi(pars->color[pars->z]) < 0 || pars->h != 3
			|| ft_isdigit_str(pars->color[pars->z]) == 0)
		{
			ft_free_split(pars->color, pars->h);
			ft_error_return(-4, pars, argv, 3);
		}
		(pars->z)++;
	}
	pars->red_ceiling = ft_atoi(pars->color[0]);
	pars->green_ceiling = ft_atoi(pars->color[1]);
	pars->blue_ceiling = ft_atoi(pars->color[2]);
	ft_free_split(pars->color, pars->h);
	return (1);
}

void	ft_verif_ceiling(char **map, t_verification *pars, char *argv)
{
	pars->d = 0;
	pars->z = 0;
	if (map[pars->i][pars->j] == 'C'
		&& map[pars->i][pars->j + 1] == ' ' && pars->tab_gestion[5] == 0)
	{
		ft_verif_ceiling_bis(map, pars, argv);
		pars->tab_gestion[5] = 1;
	}
	else if (map[pars->i][pars->j] == 'C'
		&& map[pars->i][pars->j + 1] == ' ' && pars->tab_gestion[5] == 1)
	{
		ft_error_return(-3, pars, argv, 3);
	}
}

void	ft_verif_all_elements(t_verification *pars, char *argv)
{
	if (pars->north_texture == NULL || pars->south_texture == NULL
		|| pars->east_texture == NULL || pars->west_texture == NULL
		|| pars->red_ceiling == -1
		|| pars->green_ceiling == -1 || pars->blue_ceiling == -1
		|| pars->red_floor == -1 || pars->green_floor == -1
		|| pars->blue_floor == -1)
	{
		ft_error_return(-4, pars, argv, 3);
	}
}

int	verif_number(long long int number)
{
	if (number < 0)
		return (0);
	if (number > 255)
		return (0);
	return (1);
}
