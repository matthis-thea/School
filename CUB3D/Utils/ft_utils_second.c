/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_second.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:56:53 by haze              #+#    #+#             */
/*   Updated: 2023/10/30 11:36:21 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

int	ft_free_initialisation_bis(t_verification *pars, char *argv, int paramatres)
{
	if (paramatres == 3)
	{
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
		ft_free_malloc(pars->color, pars->c);
		free(pars);
	}
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
