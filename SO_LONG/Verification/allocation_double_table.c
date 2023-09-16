/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_double_table.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:23:11 by mthea             #+#    #+#             */
/*   Updated: 2023/01/18 11:39:37 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

char	**ft_free_malloc(char **tab, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	*ft_strdup(char *source)
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
	while (i < taille)
	{
		str[i] = source[i];
		i++;
	}
	str[taille] = 0;
	return (str);
}

int	ft_allocation_lines(char *map)
{
	int		fd;
	char	*string;
	int		i;

	fd = open(map, O_RDONLY, O_CREAT);
	if (fd == -1)
		return (0);
	i = 0;
	while (1)
	{
		string = get_next_line(fd);
		if (!string)
			break ;
		free(string);
		i++;
	}
	return (i);
}

char	**ft_allocation_colums(char **tab, char *map)
{
	int		fd;
	char	*string;
	int		i;

	fd = open(map, O_RDONLY, O_CREAT);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (1)
	{
		string = get_next_line(fd);
		if (!string)
			break ;
		tab[i] = ft_strdup(string);
		if (!tab[i])
			return (ft_free_malloc(tab, i));
		free(string);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_allocation_totale(char *map)
{
	char	**string;
	int		taille;

	string = NULL;
	taille = ft_allocation_lines(map);
	string = malloc(sizeof(char *) * taille + 1);
	if (!string)
	{
		ft_printf("Error\nDynamics allocation has failed !\n");
		return (NULL);
	}
	string = ft_allocation_colums(string, map);
	if (!string)
	{
		ft_printf("Error\nDynamics allocation has failed !\n");
		return (NULL);
	}
	string[taille] = 0;
	return (string);
}
