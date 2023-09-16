/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:02:15 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 14:08:59 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

void	ft_length_fivebis_two(t_swap *s, int taille, int posi)
{
	if (posi <= 3)
		ft_ra(s, taille);
	else
		ft_rra(s, taille);
}
