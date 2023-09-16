/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:02:58 by mthea             #+#    #+#             */
/*   Updated: 2023/01/28 16:32:16 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

int	ft_free_all_loose(t_manage *man)
{
	free(man->map);
	free(man->mlx);
	free(man->copie);
	free(man->img);
	free(man->image);
	free(man->texture);
	free(man->texture_p);
	ft_printf("You failed\n");
	exit(EXIT_SUCCESS);
}

int	ft_free_all_won(t_manage *man)
{
	free(man->map);
	free(man->mlx);
	free(man->copie);
	free(man->img);
	free(man->image);
	free(man->texture);
	free(man->texture_p);
	ft_printf("Congratulations\n You won\n");
	exit(EXIT_SUCCESS);
}

void	count_pos_init(t_manage *man)
{
	man->p_x = ft_position_p_columns(man->map);
	man->p_y = ft_position_p_line(man->map);
	man->all_items = ft_verification_items(man->map);
	man->count_items = 0;
	man->col = ft_number_columns(man->map) - 1;
	man->lin = ft_number_lines(man->map);
	man->c_m = 0;
}

int	allocation_struct(t_manage *man, char *argv)
{
	int	verification;

	man->copie = ft_allocation_totale(argv);
	if (!man->copie)
		return (0);
	verification = ft_final_verification(man->copie);
	if (verification == 0)
	{
		free(man->copie);
		return (0);
	}
	man->map = ft_allocation_totale(argv);
	if (!man->map)
		ft_free_all_loose(man);
	count_pos_init(man);
	man->mlx = mlx_init(man->col * 64, man->lin * 64, "SO_LONG", true);
	if (!man->mlx)
		ft_free_all_loose(man);
	man->x = 0;
	man->y = 0;
	return (1);
}

int32_t	main(int argc, char **argv)
{
	t_manage	*man;
	int			verification;

	man = malloc(sizeof(t_manage));
	verification = verification_file_name(argv[1]);
	if (verification == 0)
	{
		ft_printf("Error\nWrong extensions\n");
		return (0);
	}
	verification = allocation_struct(man, argv[1]);
	if (verification == 0)
		return (0);
	if (argc == 2)
		loop(man);
	else
		ft_printf("Error\nPlease enter just 2 arguments\n");
	return (0);
}
