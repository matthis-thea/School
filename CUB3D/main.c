/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:22:05 by haze              #+#    #+#             */
/*   Updated: 2023/11/02 13:55:30 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/ft_parsing.h"

void	lecture(char **map, t_verification *pars)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("-%s-\n", map[i]);
		i++;
	}
	printf ("Value of the texture north %s-\n", pars->north_texture);
	printf ("Value of the texture south %s-\n", pars->south_texture);
	printf ("Value of the texture east %s-\n", pars->east_texture);
	printf ("Value of the texture west %s-\n", pars->west_texture);
	printf ("Value of the red floor %d-\n", pars->red_floor);
	printf ("Value of the green floor %d-\n", pars->green_floor);
	printf ("Value of the blue floor %d-\n", pars->blue_floor);
	printf ("Value of the red ceiling %d-\n", pars->red_ceiling);
	printf ("Value of the green ceiling %d-\n", pars->green_ceiling);
	printf ("Value of the blue ceiling %d-\n", pars->blue_ceiling);
	printf("Value of orientation of the player %c-\n", pars->orientation);
	printf("Value of the position x of the player %d-\n", pars->player_x);
	printf("Value of the position y of the player %d-\n", pars->player_y);
	printf("Taille map max en x %d\n", pars->size_map_x);
	printf("Taille map max en y %d\n", pars->size_map_y);
}

int	main(int argc, char **argv)
{
	t_verification	*pars;

	pars = malloc(sizeof(t_verification));
	if (!pars)
		return (0);
	ft_all_verification(pars, argv[1], argc);
	graph(pars);
	quit(pars);
	return (0);
}
