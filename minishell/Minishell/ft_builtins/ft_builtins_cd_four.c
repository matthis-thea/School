/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_cd_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:35:18 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 10:59:08 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	replace_pwd_normal(t_mini *mini, int i, int j, int z)
{
	mini->boolean = chdir(mini->dup_cd);
	if (mini->boolean == -1)
	{
		printf("Minishell: cd: %s ", mini->dup_cd);
		printf("est un fichier ou dossier inexistant\n");
		mini->status = 1;
		return (0);
	}
	while (mini->s_dup_env[i][0] != '.')
	{
		if (mini->s_dup_env[i][0] == 'P' && mini->s_dup_env[i][1] == 'W'
		&& mini->s_dup_env[i][2] == 'D' && mini->s_dup_env[i][3] == '=')
		{
			j += 3;
			while (mini->dup_cd[z])
			{
				mini->s_dup_env[i][j++] = mini->dup_cd[z++];
			}
			mini->s_dup_env[i][j] = '\0';
			return (1);
		}
		i++;
	}
	return (1);
}

int	cd_error(t_mini *mini)
{
	if (mini->cd_bool != 3)
	{
		printf("Minishell: cd: HOME not set\n");
		return (0);
	}
	return (1);
}

void	put_value_dup_help(t_mini *mini, int *i, int *z, char **cmd)
{
	if (cmd[1][*i] == '.' && cmd[1][*i + 1] == '/' && cmd[1][*i])
		(*i)++;
	else if (cmd[1][*i] == '.' && cmd[1][*i + 1] == '.' && cmd[1][*i])
	{
		while (mini->dup_cd[*z] != '/' && *z >= 2)
			(*z)--;
		mini->dup_cd[*z] = '\0';
		(*i)++;
		(*i)++;
	}
	else if (cmd[1][*i] != '.' && cmd[1][*i + 1] != '.' && cmd[1][*i])
	{
		if (*z != 1)
		{
			mini->dup_cd[*z] = '/';
			(*z)++;
		}
		while (cmd[1][*i] != '/' && cmd[1][*i])
		{
			mini->dup_cd[*z] = cmd[1][*i];
			(*z)++;
			(*i)++;
		}
		mini->dup_cd[*z] = '\0';
	}
}

void	cd_intro_alloc(char **cmd, t_mini *mini, int *i)
{
	while (cmd[*i])
		(*i)++;
	mini->str = pwd_search(mini);
	alloc_cd(mini);
	mini->home = getenv("HOME");
}
