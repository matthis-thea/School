/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1011/09/17 11:10:51 by parsib            #+#    #+#             */
/*   Updated: 2023/11/02 12:55:57 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	draw_rays(t_verification *pars)
{
	pars->ra = fix_ang(pars->pa + 30);
	pars->r = 0;
	pars->raynb = 80;
	while (pars->r < pars->raynb)
	{
		vertical_line(pars);
		horizontal_line(pars);
		draw_rays_bis(pars);
		draw_rays_ter(pars);
	}
}

void	hook(void *param)
{
	t_verification	*pars;

	pars = param;
	if (!pars->mlx)
		quit(pars);
	if (mlx_is_key_down(pars->mlx, MLX_KEY_ESCAPE))
	{
		printf("EXITING...\n");
		quit(pars);
	}
	r_l_move(pars);
	a_w_s_d_move(pars);
}

void	graph(t_verification *pars)
{
	pars->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!pars->mlx)
		quit(pars);
	pars->px = pars->player_x * 64;
	pars->py = pars->player_y * 64;
	pars->map_x = pars->size_map_x;
	pars->map_y = pars->size_map_y;
	pars->p_dir = pars->orientation;
	floor_ceiling(pars);
	load_player(pars);
	display_line(pars);
	import_textures(pars);
	spawn_look(pars);
	draw_rays(pars);
	mlx_loop_hook(pars->mlx, &hook, pars);
	mlx_loop(pars->mlx);
}
