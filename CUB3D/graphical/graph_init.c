/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:21:39 by thib              #+#    #+#             */
/*   Updated: 2023/11/02 12:39:35 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	floor_ceiling(t_verification *pars)
{
	int	height;
	int	x;
	int	y;

	x = 0;
	y = 0;
	height = HEIGHT / 2;
	pars->f_img = mlx_new_image(pars->mlx, WIDTH, HEIGHT);
	if (!pars->f_img || mlx_image_to_window(pars->mlx, pars->f_img, 0, 0) < 0)
		quit(pars);
	while (x < WIDTH)
	{
		while (y < height)
			mlx_put_pixel(pars->f_img, x, y++, get_rgba(pars->red_ceiling,
					pars->green_ceiling, pars->blue_ceiling, 255));
		y = height;
		while (y < HEIGHT)
			mlx_put_pixel(pars->f_img, x, y++, get_rgba(pars->red_floor,
					pars->green_floor, pars->blue_floor, 255));
		x++;
	}
}

void	load_player(t_verification *pars)
{
	pars->g_img = mlx_new_image(pars->mlx, 5, 5);
	if (!pars->g_img || (mlx_image_to_window(pars->mlx, pars->g_img,
				(pars->px / 3) / 5,
				(pars->py / 3) / 5)) < 0)
		quit(pars);
	memset(pars->g_img->pixels, 0, pars->g_img->width
		* pars->g_img->height * sizeof(int));
}

void	display_line(t_verification *pars)
{
	pars->pdx = cos(pars->pa) * 5;
	pars->pdy = sin(pars->pa) * 5;
	pars->l_img = mlx_new_image(pars->mlx, WIDTH, HEIGHT);
	if (!pars->l_img || (mlx_image_to_window(pars->mlx, pars->l_img, 0, 0)) < 0)
		quit(pars);
	draw_rays(pars);
}

void	import_textures(t_verification *pars)
{
	pars->twe = mlx_load_png(pars->east_texture);
	if (!pars->twe)
		quit(pars);
	pars->tea = mlx_load_png(pars->west_texture);
	if (!pars->tea)
		quit(pars);
	pars->tno = mlx_load_png(pars->north_texture);
	if (!pars->tno)
		quit(pars);
	pars->tso = mlx_load_png(pars->south_texture);
	if (!pars->tso)
		quit(pars);
}
