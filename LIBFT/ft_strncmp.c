/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:51:35 by mthea             #+#    #+#             */
/*   Updated: 2022/11/15 08:22:40 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*chaine1;
	const unsigned char	*chaine2;
	size_t				i;

	i = 0;
	chaine1 = (const unsigned char *) s1;
	chaine2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && chaine1[i] == chaine2[i] && chaine1[i] && chaine2[i])
		i++;
	if (chaine1[i] == chaine2[i])
		return (0);
	return ((chaine1[i] - chaine2[i]));
}
