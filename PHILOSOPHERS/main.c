/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/21 18:35:32 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int	second_main(t_finale *p, int error)
{
	p->fin = malloc(sizeof(t_fin) * p->base.nb_phil);
	if (!p->fin)
	{
		printf("Allocation failed !\n");
		return (0);
	}
	ft_final_parse_two(p);
	error = ft_start(p);
	if (error == 0)
		return (0);
	ft_stop(p);
	return (1);
}

int	main(int argc, char **argv)
{
	t_finale	p;
	int			error;

	error = ft_final_parse(argv, argc, &p);
	if (error == 0)
		return (0);
	error = second_main(&p, error);
	if (error == 0)
	{
		free(p.fin);
	}
	free(p.fin);
	return (0);
}
