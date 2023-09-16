/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:43:48 by haze              #+#    #+#             */
/*   Updated: 2023/03/07 14:00:29 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_includes/ft_push_swap.h"

int	ft_argc_equal_two(t_swap *s, char **argv)
{
	int	taille;
	int	verif;

	verif = 0;
	taille = ft_strlen_if_two(argv);
	s = ft_allocation_tab_bis(s, taille, argv);
	verif = ft_sort_tab_a(s);
	if (verif == 1)
	{
		ft_free_all(s);
		return (0);
	}
	ft_sort_tab_temp(s);
	ft_convert_stack_a(s);
	ft_final_sorted(s, taille);
	ft_free_all(s);
	return (0);
}

int	ft_argc_more_two(t_swap *s, char **argv, int argc)
{
	int	verif;

	verif = 0;
	s = ft_allocation_tab(s, argc - 1, argv);
	verif = ft_sort_tab_a(s);
	if (verif == 1)
	{
		ft_free_all(s);
		return (0);
	}
	ft_sort_tab_temp(s);
	ft_convert_stack_a(s);
	ft_final_sorted(s, argc - 1);
	ft_free_all(s);
	return (0);
}

int	main(int argc, char **argv)
{
	t_swap	*s;
	int		verif;

	s = NULL;
	verif = ft_verif_if_is_totale(argv, argc);
	if (verif == 0)
		return (0);
	if (argc == 2)
		ft_argc_equal_two(s, argv);
	else
		ft_argc_more_two(s, argv, argc);
	return (0);
}
