/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 22:31:38 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 13:52:24 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

int	ft_allocation_all_tab(t_swap *s)
{
	s->stack_a = malloc(sizeof(long long int) * s->max);
	if (!s->stack_a)
	{
		free(s);
		return (0);
	}
	s->stack_temp = malloc(sizeof(long long int) * s->max);
	if (!s->stack_temp)
	{
		free(s->stack_a);
		free(s);
		return (0);
	}
	s->stack_b = malloc(sizeof(long long int) * s->max);
	if (!s->stack_b)
	{
		free(s->stack_a);
		free(s->stack_temp);
		free(s);
		return (0);
	}
	return (1);
}

t_swap	*ft_allocation_tab(t_swap *s, int taille, char **argv)
{
	int	i;
	int	j;
	int	verif;

	verif = 0;
	j = 0;
	i = 1;
	s = malloc(sizeof(t_swap));
	if (!s)
		return (0);
	s->max = taille;
	s->i = 0;
	s->j = 0;
	verif = ft_allocation_all_tab(s);
	if (verif == 0)
		return (0);
	while (argv[i])
	{
		s->stack_a[j] = ft_atoi(argv[i]);
		s->stack_temp[j] = ft_atoi(argv[i]);
		s->stack_b[j] = -1;
		i++;
		j++;
	}
	return (s);
}

t_swap	*ft_allocation_tab_bis(t_swap *s, int taille, char **argv)
{
	int	verif;

	verif = 0;
	s = malloc(sizeof(t_swap));
	if (!s)
		return (0);
	s->max = taille;
	s->i = 0;
	s->j = 0;
	ft_alloc_for_two(argv, verif, s);
	return (s);
}
