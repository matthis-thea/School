/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:02:15 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 14:08:49 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

void	ft_length_three(t_swap *s, int taille)
{
	if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
		ft_sa(s);
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[1] > s->stack_a[2])
	{
		ft_sa(s);
		ft_rra(s, taille);
	}
	else if (s->stack_a[0] > s->stack_a[1] && s->stack_a[0] > s->stack_a[2])
		ft_ra(s, taille);
	else if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2])
	{
		ft_sa(s);
		ft_ra(s, taille);
	}
	else
		ft_rra(s, taille);
}

void	ft_length_fivebis(t_swap *s, int taille)
{
	taille = ft_sort_tab_a_length_five(s);
	if (taille == 1)
	{
		ft_pa(s, 3);
		return ;
	}
	ft_length_three(s, 3);
	ft_pa(s, 3);
}

void	ft_length_five(t_swap *s, int taille)
{
	int	doublon;
	int	posi;

	while (taille > 3)
	{
		posi = ft_pos(s, taille);
		ft_length_fivebis_two(s, taille, posi);
		if (s->stack_a[0] == 0)
		{
			ft_pb(s, taille);
			taille--;
			ft_realloc_stack_pb(s, taille);
			doublon = 1;
		}
		if (s->stack_a[0] == 1 && doublon == 1)
		{
			ft_pb(s, taille);
			taille--;
			ft_realloc_stack_pb(s, taille);
			doublon = 2;
		}
	}
	ft_length_fivebis(s, taille);
}

void	ft_length_four(t_swap *s, int taille)
{
	int	doublon;

	doublon = 0;
	while (doublon != 1)
	{
		if (s->stack_a[0] == 0)
		{
			ft_pb(s, taille);
			taille--;
			ft_realloc_stack_pb(s, taille);
			doublon = 1;
		}
		ft_ra(s, taille);
	}
	ft_length_three(s, taille);
	ft_pa(s, taille);
}

void	ft_final_sorted(t_swap *s, int taille)
{
	if (taille == 2)
		ft_ra(s, taille);
	else if (taille == 3)
		ft_length_three(s, taille);
	else if (taille == 4)
		ft_length_four(s, taille);
	else if (taille == 5)
		ft_length_five(s, taille);
	else
		ft_big_sorted(s);
}
