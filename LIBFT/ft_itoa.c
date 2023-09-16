/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:31:01 by mthea             #+#    #+#             */
/*   Updated: 2022/11/15 14:51:57 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, char *src)
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

static int	ft_lennumb(int n)
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

static char	*ft_tri(char *tab, int nombre)
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
