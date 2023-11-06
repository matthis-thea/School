/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:22:21 by haze              #+#    #+#             */
/*   Updated: 2023/10/31 13:58:38 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	ft_verif_if_elem_first_bis(char **map, t_verification *pars)
{
	if (map[pars->i][pars->j] == 'N'
		&& map[pars->i][pars->j + 1] == 'O'
		&& map[pars->i][pars->j + 2] == ' ')
		(pars->boolean)++;
	if (map[pars->i][pars->j] == 'S'
		&& map[pars->i][pars->j + 1] == 'O'
		&& map[pars->i][pars->j + 2] == ' ')
		(pars->boolean)++;
	if (map[pars->i][pars->j] == 'E'
		&& map[pars->i][pars->j + 1] == 'A'
		&& map[pars->i][pars->j + 2] == ' ')
		(pars->boolean)++;
	if (map[pars->i][pars->j] == 'W'
		&& map[pars->i][pars->j + 1] == 'E'
		&& map[pars->i][pars->j + 2] == ' ')
		(pars->boolean)++;
	if (map[pars->i][pars->j] == 'F'
		&& map[pars->i][pars->j + 1] == ' ')
		(pars->boolean)++;
	if (map[pars->i][pars->j] == 'C'
		&& map[pars->i][pars->j + 1] == ' ')
		(pars->boolean)++;
	if (map[pars->i][pars->j] == ',')
		pars->incr = 2;
	(pars->j)++;
}

int	ft_free_initialisation_bis(t_verification *pars, char *argv)
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

char	*ft_strdup_bis(char *source)
{
	char	*str;
	int		i;
	int		taille;

	taille = ft_strlen(source);
	str = NULL;
	i = 0;
	str = malloc(sizeof(char) * (taille + 1));
	if (!str)
		return (NULL);
	while (i < taille && source[i] != '\n' && source[i] != 32 && source[i] != 9)
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_modifed(char *source, t_verification *pars)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	str = malloc(sizeof(char) * (pars->size_map_x + 1));
	if (!str)
		return (NULL);
	while (i < pars->size_map_x && source[i] != '\n')
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_atoi_bis(const char *thestring, int valeur, int moins, int i)
{
	if (thestring[i] < 48 && thestring[i] != '\0')
		return (-2);
	if (thestring[i] > 57 && thestring[i] != '\0')
		return (-2);
	if (valeur > 255 || moins == 1)
		return (-2);
	return (valeur);
}
