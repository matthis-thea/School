/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:44:17 by mthea             #+#    #+#             */
/*   Updated: 2022/11/05 17:47:46 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int		i;

	i = 0;
	while (string[i])
	{
		i++;
	}	
	while (i > 0)
	{
		if (string[i] == (char) searchedChar)
			return ((char *)&string[i]);
		i--;
	}
	if (string[i] == (char) searchedChar)
		return ((char *)&string[i]);
	return (0);
}
