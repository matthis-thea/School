/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:22:21 by haze              #+#    #+#             */
/*   Updated: 2023/11/02 13:54:27 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

int	ft_valid_extension(int nb_arg, char *argv, t_verification *pars)
{
	pars->i = 0;
	if (nb_arg == 2)
	{
		while (argv[pars->i])
		{
			if (argv[pars->i] == '.')
			{
				if (ft_strncmp(&argv[pars->i], ".cub") == 1)
					return (1);
				else
					return (ft_error_return(-1, pars, argv, 0));
			}
			(pars->i)++;
		}
		return (ft_error_return(-1, pars, argv, 0));
	}
	return (ft_error_return(0, pars, argv, 0));
}

int	ft_size_file_cub_heigth(char *argv, t_verification *pars)
{
	int		fd;
	char	*string;

	fd = open(argv, O_RDONLY, O_CREAT);
	if (fd == -1)
		return (0);
	pars->i = 0;
	while (1)
	{
		string = get_next_line(fd);
		if (!string)
		{
			free(string);
			break ;
		}
		free(string);
		(pars->i)++;
	}
	return (pars->i);
}

int	ft_size_file_cub_length(char *argv, t_verification *pars)
{
	int		fd;
	char	*string;
	int		size_length;

	fd = open(argv, O_RDONLY, O_CREAT);
	if (fd == -1)
		return (0);
	pars->i = 0;
	pars->j = 0;
	size_length = 0;
	while (1)
	{
		string = get_next_line(fd);
		if (!string)
			break ;
		while (string[pars->j])
			(pars->j)++;
		if (pars->j > size_length)
			size_length = pars->j;
		pars->j = 0;
		free(string);
		(pars->i)++;
	}
	return (size_length);
}

int	ft_verif_if_elem_first(char **map, t_verification *pars, char *argv)
{
	(void) argv;
	pars->i = 0;
	pars->j = 0;
	pars->boolean = 0;
	pars->incr = 0;
	while (map[pars->i])
	{
		while (map[pars->i][pars->j])
			ft_verif_if_elem_first_bis(map, pars);
		if (pars->boolean == 6)
		{
			pars->j = 0;
			while (map[pars->i][pars->j])
			{
				if ((map[pars->i][pars->j] == '1'
					|| map[pars->i][pars->j] == '0') && pars->incr == 0)
					return (pars->i);
				(pars->j)++;
			}
		}
		pars->incr = 0;
		(pars->i)++;
		pars->j = 0;
	}
	return (0);
}

int	ft_all_verification(t_verification *pars, char *argv, int nb_arg)
{
	ft_initialisation_var_struc(pars);
	ft_valid_extension(nb_arg, argv, pars);
	alloc_totale(argv, pars);
	ft_verif_n_s_e_w_f_c(pars->map, pars, argv);
	verif_map_compact(pars->binary_map, pars, argv);
	ft_verif_map_elements(pars->binary_map, pars, argv);
	positon_player(pars);
	pars->argv = argv;
	ft_verification_flood_fill(pars);
	ft_verif_texture(pars, argv);
	reinitialisation_map(pars);
	return (0);
}
