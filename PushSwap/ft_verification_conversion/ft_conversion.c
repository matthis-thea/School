/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:43:48 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 16:32:56 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

int	ft_sort_tab_a(t_swap *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < s->max)
	{
		while (j < s->max)
		{
			if (s->stack_a[i] > s->stack_a[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_sort_tab_temp(t_swap *s)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = 0;
	j = 1;
	while (i < s->max)
	{
		while (j < s->max)
		{
			if (s->stack_temp[i] > s->stack_temp[j])
			{
				temp = s->stack_temp[j];
				s->stack_temp[j] = s->stack_temp[i];
				s->stack_temp[i] = temp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	ft_convert_stack_a(t_swap *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < s->max)
	{
		while (j < s->max)
		{
			if (s->stack_a[i] == s->stack_temp[j])
			{
				s->stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	ft_sorted_bis(int max_bits, int pos, t_swap *s)
{
	int	last_num;

	last_num = s->max;
	while (s->i <= max_bits)
	{
		while (s->j < s->max)
		{
			pos = s->stack_a[0];
			if (((pos >> s->i) & 1) == 1)
				ft_ra(s, last_num);
			else
			{
				ft_pb(s, last_num);
				last_num--;
				ft_realloc_stack_pb(s, last_num);
			}
			(s->j)++;
		}
		ft_pa(s, last_num);
		last_num = s->max;
		s->j = 0;
		(s->i)++;
		if (ft_sort_tab_a(s) == 1)
			return ;
	}
}

void	ft_big_sorted(t_swap *s)
{
	int	max_bits;
	int	pos;
	int	verif;

	verif = s->max - 1;
	max_bits = 0;
	pos = 0;
	while ((verif >> max_bits) != 0)
	{
		max_bits++;
	}
	verif = 0;
	ft_sorted_bis(max_bits, pos, s);
}
