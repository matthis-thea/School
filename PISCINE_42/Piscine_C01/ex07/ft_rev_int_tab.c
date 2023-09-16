/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:17:22 by mthea             #+#    #+#             */
/*   Updated: 2022/07/16 17:33:03 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	int		stockage_d;
	int		stockage_p;
	int		taille;

	i = 0;
	stockage_d = 0;
	stockage_p = 0;
	taille = size - 1;
	while (i < taille)
	{
		stockage_d = tab[taille];
		stockage_p = tab[i];
		tab[i] = stockage_d;
		tab[taille] = stockage_p;
		i++;
		taille--;
	}
}
