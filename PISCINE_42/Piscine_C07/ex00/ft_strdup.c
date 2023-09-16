/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:49:14 by mthea             #+#    #+#             */
/*   Updated: 2022/07/27 12:40:30 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	strlength(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*destination;
	int		taille;
	int		i;

	i = 0;
	taille = strlength(src);
	destination = malloc(sizeof(*src) * taille);
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
