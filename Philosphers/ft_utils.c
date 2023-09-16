/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:06:02 by mthea             #+#    #+#             */
/*   Updated: 2023/05/21 17:41:05 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_include.h"

long long int	ft_atoi(char *thestring)
{
	int				i;
	long long int	valeur;
	int				moins;

	i = 0;
	valeur = 0;
	moins = 0;
	while ((thestring[i] >= 9 && thestring[i] <= 13) || thestring[i] == 32)
		i++;
	if (thestring[i] == 43 || thestring[i] == 45)
	{
		if (thestring[i] == 45)
			moins++;
		i++;
	}
	while (thestring[i] && (thestring[i] >= 48 && thestring[i] <= 57))
	{
		valeur = ((valeur * 10) + (thestring[i] - 48));
		i++;
	}
	if (moins)
		valeur = -valeur;
	if (!(thestring[i] >= 48 && thestring[i] <= 57) && valeur == 0)
		return (0);
	return (valeur);
}

int	ft_error(int error)
{
	if (error == -2)
		printf("Please, enter valid argument !\n");
	else if (error == -1)
		printf("Error in the creation of the threads");
	return (0);
}

long int	ft_long_error(void)
{
	printf("Error in the function Gettimeofday\n");
	return (0);
}

long int	ft_actual_time(void)
{
	long int			time;
	struct timeval		current_time;
	long int			error;

	time = 0;
	error = gettimeofday(&current_time, NULL);
	if (error == -1)
		ft_long_error();
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = ft_actual_time();
	while ((ft_actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
