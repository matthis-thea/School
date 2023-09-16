/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:30:18 by mthea             #+#    #+#             */
/*   Updated: 2022/11/15 14:23:41 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	taille_dest;

	i = 0;
	taille_dest = 0;
	while (dst[taille_dest] && taille_dest < size)
		taille_dest++;
	while (src[i] && size && i + taille_dest < size - 1)
	{
		dst[taille_dest + i] = src[i];
		i++;
	}
	if (taille_dest < size)
		dst[taille_dest + i] = '\0';
	i = 0;
	while (src[i])
			i++;
	return (taille_dest + i);
}
