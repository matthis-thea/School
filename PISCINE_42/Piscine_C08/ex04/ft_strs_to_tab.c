/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:09:17 by mthea             #+#    #+#             */
/*   Updated: 2022/08/02 16:19:20 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	strlength(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*destination;
	int		taille;
	int		i;

	i = 0;
	taille = strlength(src);
	destination = malloc(sizeof(char) * (taille + 1));
	if (destination == NULL)
		return (0);
	while (src[i] != '\0')
	{
		destination[i] = src[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str		*tab;
	int						i;

	tab = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (tab == 0 | tab < 0)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = strlength(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].size = 1;
	tab[i].str = 0;
	tab[i].copy = 0;
	return (tab);
}
