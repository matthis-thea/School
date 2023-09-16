/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:23:26 by mthea             #+#    #+#             */
/*   Updated: 2023/08/20 13:01:47 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	my_pwd(char **cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		while (cmd[i][j])
		{
			if (cmd[i][j] == 'P' && cmd[i][j + 1] == 'W'
			&& cmd[i][j + 2] == 'D')
			{
				printf("%s\n", &cmd[i][j + 4]);
				return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	printf("PWD not found\n");
	return (0);
}
