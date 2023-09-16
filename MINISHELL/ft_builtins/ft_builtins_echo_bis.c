/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_echo_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:35:18 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 12:55:49 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	echo_dollards_no_space(t_mini *mini, char **cmd, int z, int i)
{
	mini->bool_echo = 1;
	while (mini->s_dup_env[z][0] != '.')
	{
		if (ft_strncmp(&cmd[i][1], &mini->s_dup_env[z][0],
				ft_strlen(&cmd[i][1])) && mini->bool_echo)
		{
			printf("%s", &mini->s_dup_env[z][ft_strlen(&cmd[i][2]) + 2]);
			mini->bool_echo = 0;
		}
		z++;
	}
}

void	echo_dollards_space(t_mini *mini, char **cmd, int z, int i)
{
	mini->bool_echo = 1;
	while (mini->s_dup_env[z][0] != '.')
	{
		if (ft_strncmp(&cmd[i][2], &mini->s_dup_env[z][0],
				ft_strlen(&cmd[i][2])) && mini->bool_echo)
		{
			printf("%s", &mini->s_dup_env[z][ft_strlen(&cmd[i][2]) + 1]);
			mini->bool_echo = 0;
		}
		z++;
	}
}
