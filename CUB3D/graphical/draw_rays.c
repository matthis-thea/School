/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:18:38 by tserdet           #+#    #+#             */
/*   Updated: 2023/11/04 13:42:55 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	draw_rays_bis(t_verification *pars)
{
	if (pars->dis_v < pars->dis_h)
	{
		if (cos(deg_to_rad(pars->ra)) > 0.001)
			pars->t = pars->twe;
		else
			pars->t = pars->tea;
	}
	else if (pars->dis_v >= pars->dis_h)
	{
		if (sin(deg_to_rad(pars->ra)) > 0.001)
			pars->t = pars->tno;
		else
			pars->t = pars->tso;
	}
	else
		pars->t = pars->tno;
	if (pars->dis_v < pars->dis_h)
	{
		pars->rx = pars->vy;
		pars->ry = pars->vx;
		pars->dis_h = pars->dis_v;
	}
	pars->ca = fix_ang(pars->pa - pars->ra);
	pars->dis_h = pars->dis_h * cos(deg_to_rad(pars->ca));
	pars->line_h = (MAPS * 640) / (pars->dis_h);
}

void	draw_rays_ter(t_verification *pars)
{
	pars->ty_step = 32.0 / (float) pars->line_h;
	pars->ty_off = 0;
	if (pars->line_h > 640)
	{
		pars->ty_off = (pars->line_h - 640) / 2.0;
		pars->line_h = 640;
	}
	pars->line_off = 320 - (pars->line_h >> 1);
	pars->y = 0;
	pars->a = 0;
	pars->g = 0;
	pars->ty = pars->ty_off * pars->ty_step;
	pars->tx = (int)(pars->rx / 2.0) % 32;
	while (pars->y < pars->line_h)
	{
		pars->g = pixel_to_color(pars->tx, pars->ty, pars);
		pars->a = 0;
		while (pars->a < 640 / pars->raynb)
			mlx_put_pixel(pars->l_img, pars->r * 640 / pars->raynb + pars->a++,
				pars->line_off + pars->y, pars->g);
		pars->ty += pars->ty_step;
		pars->y++;
	}
	pars->ra = fix_ang(pars->ra - 1);
	pars->r++;
}
