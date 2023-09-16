/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:03:45 by mthea             #+#    #+#             */
/*   Updated: 2023/01/28 16:32:33 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

int	ft_open_map(t_manage *m)
{
	while (m->map[m->y])
	{
		while (m->map[m->y][m->x])
		{
			if (m->map[m->y][m->x] == '1')
				ft_placement_asset("./Window_management/Images/1.png", m);
			else
			{
				if (m->map[m->y][m->x] == '\n')
					break ;
				ft_placement_asset("./Window_management/Images/all.png", m);
			}
			if (m->map[m->y][m->x] == 'C')
				ft_placement_asset("./Window_management/Images/c.png", m);
			if (m->map[m->y][m->x] == 'G')
				ft_placement_asset("./Window_management/Images/g.png", m);
			if (m->map[m->y][m->x] == 'E')
				ft_placement_asset("./Window_management/Images/e.png", m);
			(m->x)++;
		}
		(m->y)++;
		m->x = 0;
	}
	return (1);
}

int	ft_open_map_2(t_manage *m)
{
	while (m->map[m->y])
	{
		while (m->map[m->y][m->x])
		{
			if (m->map[m->y][m->x] == 'P')
				ft_placement_p("./Window_management/Images/p.png", m);
			(m->x)++;
		}
		(m->y)++;
		m->x = 0;
	}
	return (1);
}

void	string_count(t_manage *man)
{
	ft_printf("Move : %d\n", man->c_m);
	man->c_m += 1;
}

void	ft_key_h(mlx_key_data_t keydata, void *param)
{
	t_manage	*man;

	man = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(man->mlx);
	if (mlx_is_key_down(man->mlx, MLX_KEY_W) && ft_m_up(man) == 1)
	{
		string_count(man);
		man->img->instances[0].y -= 1 * 64;
	}
	if (mlx_is_key_down(man->mlx, MLX_KEY_S) && ft_m_down(man) == 1)
	{
		string_count(man);
		man->img->instances[0].y += 1 * 64;
	}
	if (mlx_is_key_down(man->mlx, MLX_KEY_A) && ft_m_left(man) == 1)
	{
		string_count(man);
		man->img->instances[0].x -= 1 * 64;
	}
	if (mlx_is_key_down(man->mlx, MLX_KEY_D) && ft_m_right(man) == 1)
	{
		string_count(man);
		man->img->instances[0].x += 1 * 64;
	}
}

void	loop(t_manage *man)
{
	ft_open_map(man);
	man->x = 0;
	man->y = 0;
	ft_open_map_2(man);
	mlx_key_hook(man->mlx, &ft_key_h, man);
	mlx_loop(man->mlx);
	ft_printf("bye\n");
}
