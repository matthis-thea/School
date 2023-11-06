/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_h_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:25:07 by tserdet           #+#    #+#             */
/*   Updated: 2023/11/02 14:03:20 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	vertical_line_bis(t_verification *pars)
{
	while (pars->dof < 50)
	{
		pars->mx = (int)(pars->rx) >> 6;
		pars->my = (int)(pars->ry) >> 6;
		pars->mp = pars->my * pars->map_x + pars->mx;
		if (pars->mx + pars->my * pars->map_x > 0 && pars->mx
			< pars->map_x && pars->my
			< pars->map_y && pars->binary_map[pars->my][pars->mx] == '1')
		{
			pars->dof = 50;
			pars->dis_v = cos(deg_to_rad(pars->ra)) * (pars->rx - pars->px)
				- sin(deg_to_rad(pars->ra)) * (pars->ry - pars->py);
		}
		else
		{
			pars->rx += pars->xo;
			pars->ry += pars->yo;
			pars->dof += 1;
		}
	}
	pars->vx = pars->rx;
	pars->vy = pars->ry;
}

void	vertical_line(t_verification *pars)
{
	pars->dof = 0;
	pars->dis_v = 1000000;
	pars->tan = tan(deg_to_rad(pars->ra));
	if (cos(deg_to_rad(pars->ra)) > 0.001)
	{
		pars->rx = (((int) pars->px >> 6) << 6) + 64;
		pars->ry = (pars->px - pars->rx) * pars->tan + pars->py;
		pars->xo = 64;
		pars->yo = -pars->xo * pars->tan;
	}
	else if (cos(deg_to_rad(pars->ra)) < -0.001)
	{
		pars->rx = (((int) pars->px >> 6) << 6) - 0.0001;
		pars->ry = (pars->px - pars->rx) * pars->tan + pars->py;
		pars->xo = -64;
		pars->yo = -pars->xo * pars->tan;
	}
	else
	{
		pars->rx = pars->px;
		pars->ry = pars->py;
		pars->dof = 50;
	}
	vertical_line_bis(pars);
}

void	horizontal_line_bis(t_verification *pars)
{
	while (pars->dof < 50)
	{
		pars->mx = (int)(pars->rx) >> 6;
		pars->my = (int)(pars->ry) >> 6;
		pars->mp = pars->my * pars->map_x + pars->mx;
		if (pars->mx + pars->my * pars->map_x > 0 && pars->mx < pars->map_x
			&& pars->my < pars->map_y
			&& pars->binary_map[pars->my][pars->mx] == '1')
		{
			pars->dof = 50;
			pars->dis_h = cos(deg_to_rad(pars->ra)) * (pars->rx - pars->px)
				- sin(deg_to_rad(pars->ra)) * (pars->ry - pars->py);
		}
		else
		{
			pars->rx += pars->xo;
			pars->ry += pars->yo;
			pars->dof += 1;
		}
	}
}

void	horizontal_line(t_verification *pars)
{
	pars->dof = 0;
	pars->dis_h = 100000;
	pars->tan = 1.0 / pars->tan;
	if (sin(deg_to_rad(pars->ra)) > 0.001)
	{
		pars->ry = (((int) pars->py >> 6) << 6) - 0.0001;
		pars->rx = (pars->py - pars->ry) * pars->tan + pars->px;
		pars->yo = -64;
		pars->xo = -pars->yo * pars->tan;
	}
	else if (sin(deg_to_rad(pars->ra)) < -0.001)
	{
		pars->ry = (((int)pars->py >> 6) << 6) + 64;
		pars->rx = (pars->py - pars->ry) * pars->tan + pars->px;
		pars->yo = 64;
		pars->xo = -pars->yo * pars->tan;
	}
	else
	{
		pars->rx = pars->px;
		pars->ry = pars->py;
		pars->dof = 50;
	}
	horizontal_line_bis(pars);
}
