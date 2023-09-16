/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:45:44 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 13:52:04 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

int	ft_realloc_stack_pb(t_swap *s, int max)
{
	int	i;

	i = 0;
	while (i < max + 1)
	{
		s->stack_temp[i] = s->stack_a[i];
		i++;
	}
	free(s->stack_a);
	s->stack_a = malloc(sizeof(long long int) * max);
	if (!s->stack_a)
		return (0);
	i = 1;
	while (i <= max)
	{
		s->stack_a[i - 1] = s->stack_temp[i];
		i++;
	}
	return (1);
}

void	ft_realloc_stack_pa_bis(t_swap *s, int *j, int *i, int *max)
{
	while (*i >= 0)
	{
		s->stack_a[*j] = s->stack_temp[*i];
		(*j)--;
		(*i)--;
	}
	s->temp = *j;
	*j = *max - 1;
	while (*j > 0)
	{
		*i = s->stack_b[*j];
		if (*i == -1)
			break ;
		(*j)--;
	}
	(*j)++;
	*i = 0;
	while (*j < s->max)
	{
		s->stack_a[s->temp] = s->stack_b[*j];
		ft_printf("pa\n");
		s->temp--;
		(*j)++;
	}
}

int	ft_realloc_stack_pa(t_swap *s, int max)
{
	int	i;
	int	j;

	j = s->max - 1;
	i = 0;
	while (i < max)
	{
		s->stack_temp[i] = s->stack_a[i];
		i++;
	}
	free(s->stack_a);
	s->stack_a = malloc(sizeof(long long int) * s->max);
	if (!s->stack_a)
		return (0);
	i--;
	ft_realloc_stack_pa_bis(s, &j, &i, &max);
	return (1);
}

int	ft_realloc_stack_b(t_swap *s)
{
	int	j;

	j = 0;
	free(s->stack_b);
	s->stack_b = malloc(sizeof(long long int) * s->max);
	if (!s->stack_b)
		return (0);
	while (j < s->max)
	{
		s->stack_b[j] = -1;
		j++;
	}
	return (1);
}
