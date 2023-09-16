/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_cd_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:55:41 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 11:02:42 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	affichage_pwd(char **cmd, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("~");
	while (cmd[i])
	{
		while (cmd[i][j])
		{
			if (cmd[i][j] == 'P' && cmd[i][j + 1] == 'W'
			&& cmd[i][j + 2] == 'D')
			{
				printf("%s\n", &cmd[i][ft_strlen(mini->home - 1)]);
				return ;
			}
			j++;
		}
		i++;
		j = 0;
	}
	printf("PWD not found\n");
	return ;
}

void	dollards_cd_no_space(t_mini *mini, int z, char **cmd)
{
	while (mini->s_dup_env[z][0] != '.')
	{
		if (ft_strncmp(&cmd[1][2], mini->s_dup_env[z], ft_strlen(&cmd[1][2])))
		{
			mini->dup_cd = &mini->s_dup_env[z][ft_strlen(&cmd[1][2]) + 1];
			mini->bool_echo = 0;
		}
		z++;
	}
}

void	dollards_cd_space(t_mini *mini, int z, char **cmd)
{
	while (mini->s_dup_env[z][0] != '.')
	{
		if (ft_strncmp(&cmd[1][3], mini->s_dup_env[z], ft_strlen(&cmd[1][3])))
		{
			mini->dup_cd = &mini->s_dup_env[z][ft_strlen(&cmd[1][3]) + 1];
			mini->bool_echo = 0;
		}
		z++;
	}
}

void	dollards_cd_end(t_mini *mini, int z, char **cmd)
{
	int	dd;
	int	d ;

	dd = 0;
	d = 2;
	if (!cmd[d])
	{
		mini->dup_cd[z] = '/';
		mini->dup_cd[z + 1] = '\0';
	}
	else
	{
		while (cmd[d])
		{
			while (cmd[d][dd])
			{
				mini->dup_cd[z] = cmd[d][dd];
				dd++;
				z++;
			}
			d++;
			dd++;
		}
		mini->dup_cd[z] = '\0';
	}
}

void	dollards_cd(t_mini *mini, int z, char **cmd)
{
	if (cmd[1][1] == '$')
		dollards_cd_no_space(mini, z, cmd);
	else
		dollards_cd_space(mini, z, cmd);
	while (mini->dup_cd[z])
		z++;
	dollards_cd_end(mini, z, cmd);
}
