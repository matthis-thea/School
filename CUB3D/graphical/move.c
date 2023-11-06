/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:36:24 by tserdet           #+#    #+#             */
/*   Updated: 2023/11/01 12:55:55 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	r_l_move(t_verification *pars)
{
	if (mlx_is_key_down(pars->mlx, MLX_KEY_RIGHT))
	{
		pars->pa -= 5;
		pars->pa = fix_ang(pars->pa);
		pars->pdx = cos(deg_to_rad(pars->pa));
		pars->pdy = -sin(deg_to_rad(pars->pa));
		memset(pars->l_img->pixels, 0, pars->l_img->width
			* pars->l_img->height * sizeof(int));
		draw_rays(pars);
	}
	if (mlx_is_key_down(pars->mlx, MLX_KEY_LEFT))
	{
		pars->pa += 5;
		pars->pa = fix_ang(pars->pa);
		pars->pdx = cos(deg_to_rad(pars->pa));
		pars->pdy = -sin(deg_to_rad(pars->pa));
		memset(pars->l_img->pixels, 0, pars->l_img->width
			* pars->l_img->height * sizeof(int));
		draw_rays(pars);
	}
}

void	a_w_s_d_move_bis(t_verification *pars)
{
	if (mlx_is_key_down(pars->mlx, MLX_KEY_A))
	{
		pars->px += pars->pdy * 5;
		pars->py -= pars->pdx * 5;
		memset(pars->l_img->pixels, 0, pars->l_img->width
			* pars->l_img->height * sizeof(int));
		draw_rays(pars);
	}
	if (mlx_is_key_down(pars->mlx, MLX_KEY_D))
	{
		pars->px -= pars->pdy * 5;
		pars->py += pars->pdx * 5;
		memset(pars->l_img->pixels, 0, pars->l_img->width
			* pars->l_img->height * sizeof(int));
		draw_rays(pars);
	}
}

void	a_w_s_d_move(t_verification *pars)
{
	if (mlx_is_key_down(pars->mlx, MLX_KEY_W))
	{
		pars->px += pars->pdx * 5;
		pars->py += pars->pdy * 5;
		memset(pars->l_img->pixels, 0, pars->l_img->width
			* pars->l_img->height * sizeof(int));
		draw_rays(pars);
	}
	if (mlx_is_key_down(pars->mlx, MLX_KEY_S))
	{
		pars->px -= pars->pdx * 5;
		pars->py -= pars->pdy * 5;
		memset(pars->l_img->pixels, 0, pars->l_img->width
			* pars->l_img->height * sizeof(int));
		draw_rays(pars);
	}
	a_w_s_d_move_bis(pars);
}
