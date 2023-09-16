/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:02:15 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 13:53:48 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

void	ft_ra(t_swap *s, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		s->stack_temp[i] = s->stack_a[i];
		i++;
	}
	max--;
	i = 0;
	s->stack_a[max] = s->stack_temp[i];
	while (i < max)
	{
		s->stack_a[i] = s->stack_temp[i + 1];
		i++;
	}
	ft_printf("ra\n");
}

void	ft_pb(t_swap *s, int max)
{
	int	j;
	int	i;

	j = max - 1;
	i = 0;
	while (j > 0)
	{
		i = s->stack_b[j];
		if (i == -1)
			break ;
		j--;
	}
	s->stack_b[j] = s->stack_a[0];
	ft_printf("pb\n");
}

void	ft_pa(t_swap *s, int max)
{
	int	verif;

	verif = 0;
	verif = ft_realloc_stack_pa(s, max);
	if (verif == 0)
		return ;
	ft_realloc_stack_b(s);
}

void	ft_sa(t_swap *s)
{
	int	decalage;

	decalage = 0;
	decalage = s->stack_a[0];
	s->stack_a[0] = s->stack_a[1];
	s->stack_a[1] = decalage;
	ft_printf("sa\n");
}

void	ft_rra(t_swap *s, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		s->stack_temp[i] = s->stack_a[i];
		i++;
	}
	max--;
	i = 0;
	s->stack_a[i] = s->stack_temp[max];
	while (0 < max)
	{
		s->stack_a[max] = s->stack_temp[max - 1];
		max--;
	}
	ft_printf("rra\n");
}
