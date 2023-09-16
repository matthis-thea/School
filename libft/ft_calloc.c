/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:16:27 by mthea             #+#    #+#             */
/*   Updated: 2022/11/19 13:47:45 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointeur;

	pointeur = (void *) malloc(count * size);
	if (!pointeur)
		return (NULL);
	ft_bzero(pointeur, (count * size));
	return (pointeur);
}
