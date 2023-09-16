/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:14:52 by mthea             #+#    #+#             */
/*   Updated: 2022/11/15 08:22:06 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int value, size_t n)
{
	size_t			i;
	char			*chaine;

	chaine = str;
	i = 0;
	while (i < n)
	{
		chaine[i] = value;
		i++;
	}
	return (chaine);
}
