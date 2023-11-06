/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:24:32 by thib              #+#    #+#             */
/*   Updated: 2023/11/02 12:39:48 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	pixel_to_color(uint32_t x, uint32_t y, t_verification *pars)
{
	uint8_t		*pixel;
	uint32_t	color;

	if (!pars->t)
		return (get_rgba(0, 0, 0, 255));
	if (x >= pars->t->width || y >= pars->t->height)
		return (get_rgba(0, 0, 0, 255));
	pixel = &pars->t->pixels[(y * pars->t->width + x)
		* pars->t->bytes_per_pixel];
	color = (pixel[0] << 24) + (pixel[1] << 16) + (pixel[2] << 8) + pixel[3];
	return (color);
}

float	deg_to_rad(int a)
{
	return (a * PI / 180.0);
}

int	fix_ang(int a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}
