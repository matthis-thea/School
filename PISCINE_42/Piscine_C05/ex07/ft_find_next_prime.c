/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:18:07 by mthea             #+#    #+#             */
/*   Updated: 2022/07/24 15:18:52 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_prime(int nb)
{
	int	diviseur;

	diviseur = 2;
	if (nb < 0)
		return (0);
	if ((nb == 0) || (nb == 1))
		return (0);
	while (diviseur <= nb / 2)
	{
		if (nb % diviseur == 0)
			return (0);
		diviseur++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	return (ft_find_next_prime(nb + 1));
}
