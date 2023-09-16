/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications_filename_letters.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:01:12 by mthea             #+#    #+#             */
/*   Updated: 2023/01/28 15:12:35 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

int	verification_file_name(char *argv)
{
	char	*buffer[200];
	int		fd;
	int		number;
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY, O_CREAT);
	number = read(fd, buffer, 200);
	if (number <= 0)
		return (0);
	i = strlen(argv);
	if (argv[i - 1] == 'r' && argv[i - 2] == 'e'
		&& argv[i - 3] == 'b' && argv[i - 4] == '.')
		return (1);
	else
		return (0);
	return (1);
}

int	ft_verification_items_letters(char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'P'
				|| map[i][j] == 'E' || map[i][j] == 'G' || map[i][j] == 'C'
			|| map[i][j] == '\n')
				j++;
			else
			{
				ft_printf("Error\nThe map must contain just");
				ft_printf("letters 1 or 0 or P or E or G or C\n");
				return (0);
			}
		}
		i++;
		j = 0;
	}
	return (1);
}
