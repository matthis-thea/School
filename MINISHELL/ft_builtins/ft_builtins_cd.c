/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:35:18 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 10:58:00 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	put_value_dup_dot(t_mini *mini, char **cmd)
{
	int	i;
	int	z;
	int	j;

	j = 0;
	i = 0;
	z = 0;
	while (mini->str[z])
	{
		mini->dup_cd[z] = mini->str[z];
		z++;
	}
	mini->dup_cd[z] = '\0';
	while (cmd[1][j])
		j++;
	while (cmd[1][i])
	{
		put_value_dup_help(mini, &i, &z, cmd);
		if (i >= j)
			return (0);
		i++;
	}
	return (0);
}

int	put_value_dup_bis(char **cmd, int i, int j, t_mini *mini)
{
	int	z;

	z = 0;
	if (cmd[1][0] == '~')
	{
		while (mini->home[i])
		{
			mini->dup_cd[i] = mini->home[i];
			i++;
		}
		while (cmd[1][j])
		{
			mini->dup_cd[i] = cmd[1][j];
			i++;
			j++;
		}
	mini->dup_cd[i] = '\0';
	}
	else if (cmd[1][1] == '$' || cmd[1][2] == '$')
		dollards_cd(mini, z, cmd);
	return (1);
}

int	put_value_dup(char **cmd, int i, int j, t_mini *mini)
{
	put_value_dup_bis(cmd, i, j, mini);
	if (cmd[1][0] == '/')
	{
		while (cmd[1][i])
		{
			mini->dup_cd[i] = cmd[1][i];
			if (i > 1 && cmd[1][i] == '/' && cmd[1][i + 1] == '\0')
				break ;
			i++;
		}
		mini->dup_cd[i] = '\0';
	}
	return (1);
}

int	cd_for_path_normal(t_mini *mini)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 1;
	z = 0;
	mini->cd_bool = 0;
	while (mini->s_dup_env[z][0] != '.')
	{
		if (ft_strncmp("HOME=/Users", mini->s_dup_env[z],
				ft_strlen("HOME=/Users")) && mini->cd_bool == 0)
		{
			mini->dup_cd = &mini->s_dup_env[z][ft_strlen("HOME") + 1];
			mini->cd_bool = 3;
		}
		z++;
	}
	if (cd_error(mini) == 0)
		return (0);
	z = 0;
	replace_pwd_normal(mini, i, j, z);
	return (1);
}

int	my_cd(char **cmd, t_mini *mini)
{
	int	i;

	i = 0;
	cd_intro_alloc(cmd, mini, &i);
	if (i == 1)
		cd_for_path_normal(mini);
	else if (cmd[1][0] == '~' && i == 2)
		cd_for_path(cmd, mini);
	else if (cmd[1][0] == '/' && i == 2)
		cd_for_path(cmd, mini);
	else if ((cmd[1][1] == '$' || cmd[1][2] == '$') && i >= 2)
		cd_for_path(cmd, mini);
	else if (cmd[1][0] == '.' && i == 2)
		cd_for_path_bis(cmd, mini);
	else if ((cmd[1][0] != '/' && cmd[1][1] != '.'))
		cd_for_path_bis(cmd, mini);
	else if (cmd[1][0] == '/' && cmd[1][0] == '/')
		affichage_pwd(mini->s_dup_env, mini);
	else if (cmd[3])
	{
		mini->status = 1;
		printf("Minishell: cd: trop d'arguments\n");
	}
	return (mini->status);
}
