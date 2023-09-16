/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:42:48 by mthea             #+#    #+#             */
/*   Updated: 2022/07/28 11:10:12 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
int	strlength(char **strs, char *sep, int size)
{
	int	taille;
	int	i;
	int	compteur;

	taille = 0;
	compteur = 0;
	while (taille < size)
	{
		i = 0;
		while (strs[taille][i] != '\0')
		{
			i++;
			compteur++;
		}
		i = 0;
		if (taille == (size - 1))
			break ;
		while (sep[i] != '\0')
		{
			i++;
			compteur++;
		}
		taille++;
	}
	return (compteur);
}

char	*concat(char **src, int size, char *sep, char *destination)
{
	int	taille;
	int	i;
	int	j;

	taille = -1;
	j = 0;
	while (++taille < size)
	{
		i = -1;
		while (src[taille][++i] != '\0')
		{
			destination[j] = src[taille][i];
			j++;
		}
		i = -1;
		if (taille == (size - 1))
			break ;
		while (sep[++i] != '\0')
		{
			destination[j] = sep[i];
			j++;
		}	
	}
	destination[j] = '\0';
	return (destination);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		compteur;
	char	*destination;

	if (size == 0)
	{
		destination = malloc(sizeof(char) * 1);
		return (destination);
	}
	compteur = strlength(strs, sep, size);
	destination = malloc(sizeof(char) * (compteur + 1));
	destination = concat(strs, size, sep, destination);
	return (destination);
}


int main(void)
{
	char *ptr[] = {"HELLO", "TOUT", "LE", "MONDE"};
	char *sep = "+-";
	int nombre = 2;
	printf("%s", ft_strjoin(nombre, ptr, sep));


		return (0);
}
