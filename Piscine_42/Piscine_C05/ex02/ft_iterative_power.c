/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 08:40:40 by mthea             #+#    #+#             */
/*   Updated: 2022/07/23 12:39:48 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_power(int nb, int power)
{
	int	resultat;
	int	compteur;

	compteur = 0;
	resultat = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	while (compteur < power)
	{
		resultat *= nb;
		compteur++;
	}
	return (resultat);
}
