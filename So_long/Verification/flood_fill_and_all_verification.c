/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_and_all_verification.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:45:56 by mthea             #+#    #+#             */
/*   Updated: 2023/01/28 18:15:16 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

void	ft_recursive_flood(char **tab, int pos_p_x, int pos_p_y, int *item)
{
	if (tab[pos_p_x][pos_p_y] == 'C' || tab[pos_p_x][pos_p_y] == 'E')
		(*item)++;
	if (pos_p_x < 0 || pos_p_y < 0 || tab[pos_p_x][pos_p_y] == 'X' ||
	tab[pos_p_x][pos_p_y] == '1' || tab[pos_p_x][pos_p_y] == 'G')
		return ;
	tab[pos_p_x][pos_p_y] = 'X';
	ft_recursive_flood(tab, pos_p_x - 1, pos_p_y, item);
	ft_recursive_flood(tab, pos_p_x + 1, pos_p_y, item);
	ft_recursive_flood(tab, pos_p_x, pos_p_y - 1, item);
	ft_recursive_flood(tab, pos_p_x, pos_p_y + 1, item);
}

void	ft_flood_fill(char **tab, t_point position_p, int *item)
{
	ft_recursive_flood(tab, position_p.y, position_p.x, item);
}

int	ft_verification_flood_fill(char **map)
{
	int		item;
	int		item_base;
	int		exit;
	t_point	position_p;

	item = 0;
	exit = 0;
	item_base = ft_verification_items(map) + 1;
	position_p.x = ft_position_p_columns(map);
	position_p.y = ft_position_p_line(map);
	ft_flood_fill(map, position_p, &item);
	if (item != item_base)
	{
		ft_printf("The ressources of the map are not avaibles\n");
		return (0);
	}
	return (1);
}

int	ft_final_verification(char **map)
{
	int	verification;
	int	verification_flood;

	verification = ft_verification_totale(map);
	if (verification == 0)
		return (0);
	verification_flood = ft_verification_flood_fill(map);
	if (verification_flood == 0)
		return (0);
	ft_printf("Map is ok !\n");
	return (1);
}
