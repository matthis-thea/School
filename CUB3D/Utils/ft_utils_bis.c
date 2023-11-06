/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:56:53 by haze              #+#    #+#             */
/*   Updated: 2023/11/04 13:34:55 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

int	ft_initialisation_var_struc(t_verification *pars)
{
	int	i;

	i = 0;
	pars->color = NULL;
	pars->map = NULL;
	pars->binary_map = NULL;
	pars->north_texture = NULL;
	pars->south_texture = NULL;
	pars->east_texture = NULL;
	pars->west_texture = NULL;
	pars->green_floor = -1;
	pars->red_floor = -1;
	pars->blue_floor = -1;
	pars->red_ceiling = -1;
	pars->blue_ceiling = -1;
	pars->green_ceiling = -1;
	pars->boolean = 1;
	pars->bool_color = 0;
	while (i < 6)
	{
		pars->tab_gestion[i] = 0;
		i++;
	}
	return (1);
}

int	ft_free_initialisation(t_verification *pars, char *argv, int p)
{
	pars->i = ft_size_file_cub_heigth(argv, pars);
	if (p == 0)
		free(pars);
	if (p == 1)
	{
		ft_free_malloc(pars->map, pars->i);
		free(pars);
	}
	if (p == 2)
	{
		ft_free_malloc(pars->map, pars->i);
		ft_free_malloc(pars->binary_map, pars->size_map_x);
		free(pars);
	}
	if (p == 3)
		ft_free_initialisation_bis(pars, argv);
	exit(0);
}

int	ft_final_free(t_verification *pars, char *argv)
{
	pars->i = ft_size_file_cub_heigth(argv, pars);
	if (pars->east_texture != NULL)
		free(pars->east_texture);
	if (pars->north_texture != NULL)
		free(pars->north_texture);
	if (pars->south_texture != NULL)
		free(pars->south_texture);
	if (pars->west_texture != NULL)
		free(pars->west_texture);
	ft_free_malloc(pars->map, pars->i);
	ft_free_malloc(pars->binary_map, pars->bin_j);
	free(pars);
	exit(0);
}

int	ft_atoi(const char *thestring)
{
	int	i;
	int	valeur;
	int	moins;
	int	j;

	j = 0;
	moins = 0;
	i = 0;
	valeur = 0;
	while (thestring[i]
		&& ((thestring[i] >= 9 && thestring[i] <= 13) || thestring[i] == 32))
		i++;
	moins = 1;
	while (thestring[i] && (thestring[i] >= 48 && thestring[i] <= 57))
	{
		moins = 0;
		valeur = ((valeur * 10) + (thestring[i] - 48));
		i++;
		j++;
	}
	return (ft_atoi_bis(thestring, valeur, moins, i));
}

int	ft_isdigit_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 32 || str[i] == 9)
			i = i;
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
