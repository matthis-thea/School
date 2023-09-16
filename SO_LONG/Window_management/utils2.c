/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:26:08 by mthea             #+#    #+#             */
/*   Updated: 2023/01/28 15:42:32 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

char	*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	if (dst == NULL)
		return (0);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_lennumb(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_tri(char *tab, int nombre)
{
	int	i;

	i = 0;
	if (nombre < 0)
		tab[i++] = '-';
	if (nombre < 0)
		nombre = -nombre;
	i += ft_lennumb(nombre) - 1;
	while (nombre > 0)
	{
		tab[i--] = '0' + nombre % 10;
		nombre /= 10;
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = NULL;
	if (n == -2147483648)
	{
		str = (char *) malloc(sizeof(char) * 12);
		return (ft_strcpy(str, "-2147483648"));
	}
	if (n >= 0)
		str = (char *) malloc(sizeof(char) * ft_lennumb(n) + 1);
	if (n < 0)
		str = (char *) malloc(sizeof(char) * ft_lennumb(n) + 2);
	if (str == NULL)
		return (0);
	if (n == 0 || n == -0)
		return (ft_strcpy(str, "0"));
	str = ft_tri(str, n);
	if (str[0] == '-')
		str[ft_lennumb(n) + 1] = 0;
	else
		str[ft_lennumb(n)] = 0;
	return (str);
}

char	*ft_s(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;

	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (NULL);
	}
	s = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!s || !s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		s[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s[j++] = s2[i++];
	free(s1);
	s[j] = '\0';
	return (s);
}
