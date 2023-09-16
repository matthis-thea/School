/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/21 17:31:55 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void	ft_think(t_fin *p)
{
	long int		time;

	time = ft_actual_time() - p->next->time_start;
	if (!test(p))
		printf("%ldms %d is thinking\n", time, p->id_philo);
}

void	ft_eat(t_fin *p)
{
	long int		time;

	time = ft_actual_time() - p->next->time_start;
	if (!test(p))
		printf("%ldms %d is eating\n", time, p->id_philo);
}

void	ft_sleep(t_fin *p)
{
	long int		time;

	time = ft_actual_time() - p->next->time_start;
	if (!test(p))
		printf("%ldms %d is sleeping\n", time, p->id_philo);
}

void	ft_fork(t_fin *p)
{
	long int		time;

	time = ft_actual_time() - p->next->time_start;
	if (!test(p))
		printf("%ldms %d has taken a fork\n", time, p->id_philo);
}

void	ft_dead(t_fin *p)
{
	long int		time;

	time = ft_actual_time() - p->next->time_start;
	if (!test(p))
		printf("%ldms %d died\n", time, p->id_philo);
}
