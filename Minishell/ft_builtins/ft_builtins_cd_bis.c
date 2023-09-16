/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_cd_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:35:18 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 11:01:03 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	cd_for_path(char **cmd, t_mini *mini)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	j = 1;
	z = 0;
	put_value_dup(cmd, i, j, mini);
	j = 0;
	replace_pwd(mini, i, j, z);
	return (1);
}

int	cd_for_path_bis(char **cmd, t_mini *mini)
{
	int	j;
	int	z;
	int	i;

	j = 0;
	z = 0;
	i = 0;
	put_value_dup_dot(mini, cmd);
	replace_pwd(mini, i, j, z);
	return (1);
}

int	alloc_cd(t_mini *mini)
{
	mini->dup_cd = malloc(sizeof(char) * 100);
	if (!mini->dup_cd)
		return (0);
	return (1);
}

char	*pwd_search(t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mini->s_dup_env[i])
	{
		while (mini->s_dup_env[i][j])
		{
			if (mini->s_dup_env[i][j] == 'P'
			&& mini->s_dup_env[i][j + 1] == 'W'
			&& mini->s_dup_env[i][j + 2] == 'D')
			{
				return (&mini->s_dup_env[i][j + 4]);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	replace_pwd(t_mini *mini, int i, int j, int z)
{
	mini->boolean = chdir(mini->dup_cd);
	if (mini->boolean == -1)
	{
		printf("Minishell: cd: %s ", mini->dup_cd);
		printf("est un fichier ou dossier inexistant\n");
		mini->status = 1;
		return (0);
	}
	i = 0;
	z = 0;
	j = 0;
	while (mini->s_dup_env[i][0] != '.')
	{
		if (mini->s_dup_env[i][0] == 'P' && mini->s_dup_env[i][1] == 'W'
		&& mini->s_dup_env[i][2] == 'D' && mini->s_dup_env[i][3] == '=')
		{
			j += 4;
			while (mini->dup_cd[z])
				mini->s_dup_env[i][j++] = mini->dup_cd[z++];
			mini->s_dup_env[i][j] = '\0';
			return (1);
		}
		i++;
	}
	return (1);
}
