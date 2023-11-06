/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:46:23 by haze              #+#    #+#             */
/*   Updated: 2023/10/28 14:35:06 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

int	ft_strncmp(const char *s1, const char *s2)
{
	const unsigned char	*chaine1;
	const unsigned char	*chaine2;
	size_t				i;

	i = 0;
	chaine1 = (const unsigned char *) s1;
	chaine2 = (const unsigned char *) s2;
	while (chaine1[i] == chaine2[i] && chaine1[i] && chaine2[i])
		i++;
	while (chaine1[i] || chaine2[i])
		i++;
	if (chaine1[i - 1] == chaine2[i - 1] && i == 4)
		return (1);
	return (0);
}

int	ft_error_return(int v, t_verification *pars, char *argv, int p)
{
	if (v == 0)
		printf("Error\nThis program needs just two arguments !\n");
	else if (v == -1)
		printf("Error\nThe file doesn't have the good extension!\n");
	else if (v == -2)
		printf("Error\nThe file is empty\n");
	else if (v == -3)
		printf("Error\nThe file contains duplicates members\n");
	else if (v == -4)
		printf("Error\nAn items are missing\n");
	else if (v == -5)
		printf("Error\nRGB just between 0 et 255 or many numbers\n");
	else if (v == -6 || v == -7)
		printf("Error\nThe map contains duplicates members or wrong items\n");
	else if (v == -8)
		printf("Error\nThe map are not at the end\n");
	else if (v == -9)
		printf("Error\nWrong path for texture\n");
	else if (v == -10)
		printf("Error\nMap are not closed");
	else if (v == -11)
		printf("Error\nError in the dynamic allocation\n");
	ft_free_initialisation(pars, argv, p);
	return (1);
}

char	**ft_char_error_return(int v, t_verification *pars, char *argv, int p)
{
	if (v == 0)
		printf("Error\nThis program need just two arguments !\n");
	else if (v == -1)
		printf("Error\nThe file doesn't have the good extension!\n");
	else if (v == -2)
		printf("Error\nThe file are empty\n");
	else if (v == -3)
		printf("Error\nError in the dynamic allocation\n");
	else if (v == -4)
		printf("Error\nError in the file descriptor\n");
	else if (v == -5)
		printf("Error\nThe map are empty or need just at the end\n");
	else if (v == -6)
		printf("Error\nEspace needed in items or items are missing\n");
	ft_free_initialisation(pars, argv, p);
	return (NULL);
}

char	**ft_free_malloc(char **tab, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{	
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	*ft_strdup(char *source)
{
	char	*str;
	int		i;
	int		taille;

	taille = ft_strlen(source);
	str = NULL;
	i = 0;
	str = malloc(sizeof(char) * (taille + 1));
	if (!str)
		return (NULL);
	while (i < taille && source[i] != '\n')
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
