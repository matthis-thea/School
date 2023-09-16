/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/21 17:34:11 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int	ft_nb_argc(int argc)
{
	if (argc == 5 || argc == 6)
		return (1);
	return (0);
}

int	ft_if_char(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ft_if_pos(char **argv)
{
	long long int	number;
	int				i;

	i = 1;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		if (number < 0)
			return (0);
		if (number > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	ft_verif_totale(int argc, char **argv)
{
	int	number;

	number = ft_nb_argc(argc);
	if (number == 0)
		return (ft_error(-2));
	number = ft_if_char(argv);
	if (number == 0)
		return (ft_error(-2));
	number = ft_if_pos(argv);
	if (number == 0)
		return (ft_error(-2));
	return (1);
}

int	ft_final_parse(char **argv, int argc, t_finale *p)
{
	int	number;

	number = ft_verif_totale(argc, argv);
	if (number == 0)
		return (0);
	p->base.nb_phil = ft_atoi(argv[1]);
	p->base.time_die = ft_atoi(argv[2]);
	p->base.time_eat = ft_atoi(argv[3]);
	p->base.time_sleep = ft_atoi(argv[4]);
	p->base.nb_eat = -1;
	p->base.time_start = ft_actual_time();
	p->base.finish = 0;
	pthread_mutex_init(&p->base.is_dead, NULL);
	pthread_mutex_init(&p->base.verif_death, NULL);
	if (argc == 6)
		p->base.nb_eat = ft_atoi(argv[5]);
	return (1);
}
