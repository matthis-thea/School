/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:31:56 by mthea             #+#    #+#             */
/*   Updated: 2022/11/15 14:52:53 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlenft(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_strchrr(const char *string, char searchedChar)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == searchedChar)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_strrchrr(const char *string, int searchedChar)
{
	int		i;

	i = 0;
	while (string[i])
	{
		i++;
	}	
	while (i >= 0)
	{
		if (string[i] == (char) searchedChar)
			return (1);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*str;

	n = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	j = ft_strlenft(s1);
	while (s1[i] && ft_strchrr(set, s1[i]) == 1)
		i++;
	while (j > i && ft_strrchrr(set, s1[j - 1]) == 1)
		j--;
	str = (char *) malloc(sizeof(*s1) * (j - i + 1));
	if (str == NULL)
		return (0);
	while (i < j)
	{
		str[n] = s1[i];
		i++;
		n++;
	}
	str[n] = 0;
	return (str);
}
