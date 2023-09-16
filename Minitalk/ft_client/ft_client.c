/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:16:42 by mthea             #+#    #+#             */
/*   Updated: 2022/12/16 10:43:19 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../ft_printf/ft_printf.h"

int	ft_atoi(char *thestring)
{
	int	i;
	int	valeur;
	int	moins;

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

void	ft_descaling_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_descaling_char(pid, argv[2][i]);
			i++;
		}
	}
	else
		ft_printf("Please, put the good PID or just enter three arguments");
	return (0);
}
