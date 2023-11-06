/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_alloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:00:36 by haze              #+#    #+#             */
/*   Updated: 2023/10/30 11:51:54 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

char	**ft_allocation_char_map(char *argv, t_verification *pars)
{
	pars->i = ft_size_file_cub_heigth(argv, pars);
	if (pars->i == 0)
		return (ft_char_error_return(-2, pars, argv, 0));
	pars->map = malloc(sizeof(char *) * pars->i + 1);
	if (!pars->map)
		return (ft_char_error_return(-3, pars, argv, 0));
	return (pars->map);
}

char	**ft_allocation_char_map_bin(char *argv, t_verification *pars)
{
	int	i;

	i = 0;
	pars->bin_j = 0;
	pars->size_map_x = 0;
	pars->size_map_y = 0;
	i = ft_verif_if_elem_first(pars->map, pars, argv);
	if (i == 0)
		return (ft_char_error_return(-6, pars, argv, 1));
	while (pars->map[i])
	{
		if (pars->size_map_x < ft_strlen(pars->map[i]))
			pars->size_map_x = ft_strlen(pars->map[i]);
		i++;
		(pars->bin_j)++;
	}
	pars->size_map_y = pars->bin_j;
	if (pars->bin_j == 0)
		return (ft_char_error_return(-5, pars, argv, 1));
	pars->binary_map = malloc(sizeof(char *) * pars->bin_j + 1);
	if (!pars->binary_map)
		return (ft_char_error_return(-3, pars, argv, 1));
	return (pars->binary_map);
}

char	**ft_allocation_remp_map(t_verification *pars, char *argv)
{
	int		fd;
	char	*string;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY, O_CREAT);
	pars->i = ft_size_file_cub_heigth(argv, pars);
	if (fd == -1)
		return (ft_char_error_return(-4, pars, argv, 1));
	if (pars->i == 0)
		return (ft_char_error_return(-6, pars, argv, 1));
	while (i < pars->i)
	{
		string = get_next_line(fd);
		if (!string)
			break ;
		pars->map[i] = ft_strdup(string);
		if (!pars->map[i])
			ft_free_malloc(pars->map, i);
		free(string);
		i++;
	}
	pars->map[i] = NULL;
	return (pars->map);
}

char	**ft_allocation_remp_binary(t_verification *pars, char *argv)
{
	int	i;
	int	j;

	j = 0;
	i = ft_verif_if_elem_first(pars->map, pars, argv);
	while (pars->map[i])
	{
		if (ft_strlen(pars->map[i]) == 1)
		{
			pars->binary_map[pars->bin_j] = NULL;
			return (pars->binary_map);
		}
		pars->binary_map[j] = ft_strdup_modifed(pars->map[i], pars);
		if (!pars->binary_map[j])
			ft_free_malloc(pars->binary_map, i);
		i++;
		j++;
	}
	pars->binary_map[pars->bin_j] = NULL;
	return (pars->binary_map);
}

int	alloc_totale(char *argv, t_verification *pars)
{
	ft_allocation_char_map(argv, pars);
	ft_allocation_remp_map(pars, argv);
	ft_allocation_char_map_bin(argv, pars);
	ft_allocation_remp_binary(pars, argv);
	return (1);
}
