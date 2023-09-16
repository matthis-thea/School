/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:39:10 by mthea             #+#    #+#             */
/*   Updated: 2022/11/08 13:54:03 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char			*destination;
	const char		*source;
	size_t			i;

	i = 0;
	destination = dest;
	source = src;
	if (source == 0 && destination == 0)
		return (destination);
	if (destination > source)
	{
		while (len-- > 0)
			destination[len] = source[len];
	}
	else
	{
		while (i < len)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (destination);
}
