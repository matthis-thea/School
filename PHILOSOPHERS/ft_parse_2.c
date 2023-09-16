/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/21 18:07:06 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

void	ft_final_parse_two(t_finale *p)
{
	int	i;

	i = 0;
	p->fin->inc_eat = 0;
	while (i < p->base.nb_phil)
	{
		p->fin[i].next = &p->base;
		p->fin[i].id_philo = i + 1;
		p->fin[i].fourchette_d = NULL;
		pthread_mutex_init(&p->fin[i].fourchette_g, NULL);
		pthread_mutex_init(&p->fin[i].check_write, NULL);
		pthread_mutex_init(&p->fin[i].w, NULL);
		if (p->base.nb_phil == 1)
			return ;
		if (i == p->base.nb_phil - 1)
			p->fin[i].fourchette_d = &p->fin[0].fourchette_g;
		else
			p->fin[i].fourchette_d = &p->fin[i + 1].fourchette_g;
		i++;
	}
}
