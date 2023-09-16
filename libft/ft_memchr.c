/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:10:37 by mthea             #+#    #+#             */
/*   Updated: 2022/11/15 08:21:54 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*string;
	size_t				i;

	string = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (string[i] == (const unsigned char)c)
			return ((void *)&string[i]);
		i++;
	}
	return (0);
}
