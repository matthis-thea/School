/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:43:52 by mthea             #+#    #+#             */
/*   Updated: 2022/07/29 11:16:23 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	strlenght(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	compteur;

	i = 0;
	j = 0;
	compteur = strlenght(to_find);
	while (str[i] != '\0')
	{
		if (to_find[j] == str[i])
		{
			while (to_find[j] == str[i] && j < compteur)
			{
				i++;
				j++;
			}
			if (to_find[i] == '\0' && j == compteur)
				return (str[i - compteur]);
		}
		i++;
	}
	return (str);
}
