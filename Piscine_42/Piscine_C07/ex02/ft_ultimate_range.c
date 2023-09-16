/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:48:36 by mthea             #+#    #+#             */
/*   Updated: 2022/07/26 11:37:24 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int				taille;
	int				i;

	*range = NULL;
	taille = max - min;
	i = 0;
	if (taille <= 0)
		return (0);
	*range = malloc(sizeof(int) * taille);
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	return (taille);
}
