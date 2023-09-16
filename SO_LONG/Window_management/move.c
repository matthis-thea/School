/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:37:09 by mthea             #+#    #+#             */
/*   Updated: 2023/01/28 14:02:17 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

int	ft_m_up(t_manage	*man)
{
	if (man->map[man->p_y - 1][man->p_x] == '1')
		return (0);
	else if (man->map[man->p_y - 1][man->p_x] == 'G')
		ft_free_all_loose(man);
	else
	{
		if (man->map[man->p_y - 1][man->p_x] == 'C')
		{
			ft_placement_c_u("./Window_management/Images/all.png", man);
			man->map[man->p_y - 1][man->p_x] = '0';
			mlx_delete_texture(man->texture_p);
			mlx_delete_image(man->mlx, man->img);
			ft_placement_p_move("./Window_management/Images/p.png", man);
			man->count_items += 1;
		}
		if (man->map[man->p_y - 1][man->p_x] == 'E'
		&& man->all_items == man->count_items)
		{
			man->p_y -= 1;
			ft_free_all_won(man);
		}
		man->p_y -= 1;
	}
	return (1);
}

int	ft_m_left(t_manage	*man)
{
	if (man->map[man->p_y][man->p_x - 1] == '1')
		return (0);
	else if (man->map[man->p_y][man->p_x - 1] == 'G')
		ft_free_all_loose(man);
	else
	{
		if (man->map[man->p_y][man->p_x - 1] == 'C')
		{
			ft_placement_c_l("./Window_management/Images/all.png", man);
			man->map[man->p_y][man->p_x - 1] = '0';
			mlx_delete_texture(man->texture_p);
			mlx_delete_image(man->mlx, man->img);
			ft_placement_p_move("./Window_management/Images/p.png", man);
			man->count_items += 1;
		}
		if (man->map[man->p_y][man->p_x - 1] == 'E'
		&& man->all_items == man->count_items)
		{
			man->p_x -= 1;
			ft_free_all_won(man);
		}
		man->p_x -= 1;
	}
	return (1);
}

int	ft_m_down(t_manage	*man)
{
	if (man->map[man->p_y + 1][man->p_x] == '1')
		return (0);
	else if (man->map[man->p_y + 1][man->p_x] == 'G')
		ft_free_all_loose(man);
	else
	{
		if (man->map[man->p_y + 1][man->p_x] == 'C')
		{
			ft_placement_c_d("./Window_management/Images/all.png", man);
			man->map[man->p_y + 1][man->p_x] = '0';
			mlx_delete_texture(man->texture_p);
			mlx_delete_image(man->mlx, man->img);
			ft_placement_p_move("./Window_management/Images/p.png", man);
			man->count_items += 1;
		}
		if (man->map[man->p_y + 1][man->p_x] == 'E'
		&& man->all_items == man->count_items)
		{
			man->p_y += 1;
			ft_free_all_won(man);
		}
		man->p_y += 1;
	}
	return (1);
}

int	ft_m_right(t_manage	*man)
{
	if (man->map[man->p_y][man->p_x + 1] == '1')
		return (0);
	else if (man->map[man->p_y][man->p_x + 1] == 'G')
		ft_free_all_loose(man);
	else
	{
		if (man->map[man->p_y][man->p_x + 1] == 'C')
		{
			ft_placement_c_r("./Window_management/Images/all.png", man);
			man->map[man->p_y][man->p_x + 1] = '0';
			mlx_delete_texture(man->texture_p);
			mlx_delete_image(man->mlx, man->img);
			ft_placement_p_move("./Window_management/Images/p.png", man);
			man->count_items += 1;
		}
		if (man->map[man->p_y][man->p_x + 1] == 'E'
		&& man->all_items == man->count_items)
		{
			man->p_y += 1;
			ft_free_all_won(man);
		}
		man->p_x += 1;
	}
	return (1);
}
