/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement_asset2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:05:34 by mthea             #+#    #+#             */
/*   Updated: 2023/01/28 14:07:14 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

int	ft_placement_p(char *path, t_manage *man)
{
	int				x;
	int				x_man;
	int				y_man;

	x_man = man->x;
	y_man = man->y;
	man->texture_p = mlx_load_png(path);
	if (!man->texture)
		return (0);
	man->img = mlx_texture_to_image(man->mlx, man->texture_p);
	if (!man->img)
		return (0);
	x = mlx_image_to_window(man->mlx, man->img, x_man * 64, y_man * 64);
	if (x < 0)
		exit(EXIT_FAILURE);
	return (1);
}

int	ft_placement_asset(char *path, t_manage *man)
{
	int				x;
	int				x_man;
	int				y_man;

	x_man = man->x;
	y_man = man->y;
	man->texture = mlx_load_png(path);
	if (!man->texture)
		return (0);
	man->image = mlx_texture_to_image(man->mlx, man->texture);
	if (!man->image)
		return (0);
	x = mlx_image_to_window(man->mlx, man->image, x_man * 64, y_man * 64);
	if (x < 0)
		exit(EXIT_FAILURE);
	return (1);
}
