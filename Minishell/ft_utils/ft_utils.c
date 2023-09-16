/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:55:41 by mthea             #+#    #+#             */
/*   Updated: 2023/08/18 15:02:29 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

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
		return (2);
	return (0);
}

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_deux(char **str)
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
	len = ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	str = (char *) malloc(sizeof(char) * len);
	if (str == NULL)
		return (0);
	while (s1[++i])
		str[j++] = s1[i];
	i = -1;
	str[j] = '/';
	j++;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	return (str);
}
