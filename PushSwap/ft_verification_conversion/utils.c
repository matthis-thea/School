/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:43:48 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 14:05:22 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

int	ft_strlen_if_two(char **argv)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(argv[1], ' ');
	while (tab[i])
		i++;
	ft_free_malloc(tab, i);
	return (i);
}

void	ft_alloc_for_two(char **argv, int verif, t_swap *s)
{
	char	**tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tab = ft_split(argv[1], ' ');
	verif = ft_allocation_all_tab(s);
	if (verif == 0)
		return ;
	while (tab[i])
	{
		s->stack_a[j] = ft_atoi(tab[i]);
		s->stack_temp[j] = ft_atoi(tab[i]);
		s->stack_b[j] = -1;
		i++;
		j++;
	}
	ft_free_malloc(tab, i);
}

void	ft_free_all(t_swap *s)
{
	free(s->stack_a);
	free(s->stack_b);
	free(s->stack_temp);
	free(s);
}

int	ft_pos(t_swap *s, int taille)
{
	int	i;
	int	pos;

	pos = 0;
	i = 0;
	while (i < taille)
	{
		if (s->stack_a[i] == 0)
			pos = i;
		i++;
	}
	return (pos);
}

int	ft_sort_tab_a_length_five(t_swap *s)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < 3)
	{
		while (j < 3)
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
