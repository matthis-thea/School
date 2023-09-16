/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:40:42 by mthea             #+#    #+#             */
/*   Updated: 2022/07/17 13:49:39 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int		i;
	int		j;
	int		stockage;

	i = 0;
	j = 1;
	stockage = 0;
	while (i < size - 1)
	{
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				stockage = tab[i];
				tab[i] = tab[j];
				tab[j] = stockage;
			}	
			j++;
		}
		i++;
		j = i + 1;
	}
}
