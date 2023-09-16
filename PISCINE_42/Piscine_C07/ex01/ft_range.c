/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:14:14 by mthea             #+#    #+#             */
/*   Updated: 2022/07/26 11:38:13 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tableau;
	int	taille;
	int	j;

	j = 0;
	taille = max - min;
	if (taille <= 0)
		return (0);
	tableau = malloc(sizeof(int) * taille);
	while (min < max)
	{
		tableau[j] = min;
		j++;
		min++;
	}
	return (tableau);
}
