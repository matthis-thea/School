/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/21 18:32:37 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

int	ft_start(t_finale *p)
{
	int	i;

	i = 0;
	while (i < p->base.nb_phil)
	{
		pthread_create(&p->fin[i].philo, NULL, ft_philosophers, &p->fin[i]);
		p->fin[i].last_dinner = ft_actual_time();
		ft_usleep(300);
		i++;
	}
	i = 0;
	while (i < p->base.nb_phil)
	{
		pthread_join(p->fin[i].philo, NULL);
		i++;
	}
	return (1);
}

void	*ft_philosophers(void *data)
{
	t_fin	*p;

	p = (t_fin *) data;
	if (p->id_philo % 2 == 0)
		ft_usleep(15);
	while (!test(p))
	{
		ft_launch(p);
		pthread_create(&p->verif_dead, NULL, ft_verif_dead, data);
		pthread_detach(p->verif_dead);
		if (!p->fourchette_d)
		{
			ft_dead(p);
			return (NULL);
		}
	}
	return (NULL);
}

void	*ft_verif_dead(void *data)
{
	t_fin	*p;

	p = (t_fin *) data;
	ft_usleep(p->next->time_die);
	pthread_mutex_lock(&p->next->verif_death);
	if ((ft_actual_time() - p->last_dinner) >= (long int)(p->next->time_die))
	{
		pthread_mutex_lock(&p->check_write);
		ft_dead(p);
		p->next->finish = 1;
		pthread_mutex_unlock(&p->check_write);
		pthread_mutex_unlock(&p->next->verif_death);
		return (NULL);
	}
	else if (p->inc_eat == p->next->nb_eat)
	{
		pthread_mutex_lock(&p->check_write);
		ft_each_eat(p);
		p->next->finish = 1;
		pthread_mutex_unlock(&p->check_write);
		pthread_mutex_unlock(&p->next->verif_death);
		return (NULL);
	}
	pthread_mutex_unlock(&p->next->verif_death);
	return (NULL);
}

int	test(t_fin *p)
{
	pthread_mutex_lock(&p->next->is_dead);
	if (p->next->finish)
	{
		pthread_mutex_unlock(&p->next->is_dead);
		return (1);
	}
	pthread_mutex_unlock(&p->next->is_dead);
	return (0);
}

int	ft_stop(t_finale *p)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&p->base.verif_death);
	pthread_mutex_destroy(&p->base.is_dead);
	while (i < p->base.nb_phil)
	{
		if (p->base.nb_phil > 1)
			pthread_mutex_destroy(p->fin[i].fourchette_d);
		pthread_mutex_destroy(&p->fin[i].check_write);
		pthread_mutex_destroy(&p->fin[i].w);
		i++;
	}
	return (1);
}
