/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:35:09 by mthea             #+#    #+#             */
/*   Updated: 2022/11/15 14:53:46 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlenn(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	int		len;
	int		j;

	i = -1;
	j = 0;
	len = 0;
	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	len = ((ft_strlenn(s1) + ft_strlenn(s2)) + 1);
	str = (char *) malloc(sizeof(char) * len);
	if (str == NULL)
		return (0);
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}
