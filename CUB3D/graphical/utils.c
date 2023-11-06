/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:18:58 by thib              #+#    #+#             */
/*   Updated: 2023/11/02 14:11:29 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_parsing.h"

void	quit(t_verification *pars)
{
	pars->i = ft_size_file_cub_heigth(pars->argv, pars);
	mlx_delete_texture(pars->tno);
	mlx_delete_texture(pars->tso);
	mlx_delete_texture(pars->twe);
	mlx_delete_texture(pars->tea);
	mlx_delete_image(pars->mlx, pars->g_img);
	mlx_delete_image(pars->mlx, pars->f_img);
	mlx_delete_image(pars->mlx, pars->l_img);
	mlx_terminate(pars->mlx);
	if (pars->east_texture != NULL)
		free(pars->east_texture);
	if (pars->north_texture != NULL)
		free(pars->north_texture);
	if (pars->south_texture != NULL)
		free(pars->south_texture);
	if (pars->west_texture != NULL)
		free(pars->west_texture);
	ft_free_malloc(pars->map, pars->i);
	ft_free_malloc(pars->binary_map, pars->bin_j);
	ft_free_malloc(pars->color, pars->c);
	free(pars);
	exit(1);
}

void	spawn_dir(int nmbr_loop, t_verification *pars)
{
	int	i;

	i = 0;
	while (i <= nmbr_loop)
	{
		pars->pa += 5;
		pars->pa = fix_ang(pars->pa);
		pars->pdx = cos(deg_to_rad(pars->pa));
		pars->pdy = -sin(deg_to_rad(pars->pa));
		memset(pars->l_img->pixels, 0, pars->l_img->width
			* pars->l_img->height * sizeof(int));
		draw_rays(pars);
		i++;
	}
}

void	spawn_look(t_verification *pars)
{
	if (pars->p_dir == 'N')
		spawn_dir(18, pars);
	if (pars->p_dir == 'S')
		spawn_dir(54, pars);
	if (pars->p_dir == 'E')
		spawn_dir(0, pars);
	if (pars->p_dir == 'W')
		spawn_dir(36, pars);
}
