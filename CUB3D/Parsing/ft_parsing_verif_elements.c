/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_verif_elements.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:23:25 by haze              #+#    #+#             */
/*   Updated: 2023/10/27 21:34:21 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

int	ft_verif_n_s_e_w_f_c(char **map, t_verification *pars, char *argv)
{
	pars->i = 0;
	pars->j = 0;
	pars->boolean = 1;
	while (map[pars->i])
	{
		while (map[pars->i][pars->j])
		{
			ft_verif_north(map, pars, argv);
			ft_verif_south(map, pars, argv);
			ft_verif_west(map, pars, argv);
			ft_verif_east(map, pars, argv);
			ft_verif_ceiling(map, pars, argv);
			ft_verif_floor(map, pars, argv);
			(pars->j)++;
		}
		(pars->i)++;
		pars->j = 0;
		pars->boolean = 1;
	}
	ft_verif_all_elements(pars, argv);
	return (1);
}
