/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_export_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:23:26 by mthea             #+#    #+#             */
/*   Updated: 2023/08/18 15:16:32 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	verif_export(char **cmd, int i, t_mini *mini)
{
	int	j;

	j = 0;
	mini->export_incr = 0;
	while (cmd[i][j])
	{
		if ((cmd[i][j] >= '0' && cmd[i][j] <= '9'))
			mini->export_incr++;
		if ((cmd[i][j] >= '0' && cmd[i][j] <= '9')
			|| (cmd[i][j] >= 'A' && cmd[i][j] <= 'Z')
			|| (cmd[i][j] >= 'a' && cmd[i][j] <= 'z') || cmd[i][j] == '_')
			j++;
		else
			return (1);
		if (cmd[i][j] == '=')
			break ;
	}
	if (j == mini->export_incr)
		return (1);
	if (j == 1 && cmd[i][j] == '=')
		return (1);
	return (0);
}

int	cmd_before(char **cmd, int i, t_mini *mini)
{
	int	j;

	j = 0;
	while (cmd[i][j])
	{
		if (cmd[i][j] == '-')
		{
			mini->status = 1;
			return (0);
		}
		if (cmd[i][j] == '=')
			break ;
		j++;
	}
	return (j + 1);
}

int	my_export_bis(t_mini *mini, char **cmd, int i)
{
	int	j;
	int	z;

	j = 0;
	z = 0;
	while (mini->s_dup_env[z])
	{
		mini->taille = cmd_before(cmd, i, mini);
		if (mini->taille == 1)
			return (0);
		if (ft_strncmp(cmd[i], mini->s_dup_env[z], mini->taille) > 0)
		{
			while (mini->s_export[j])
			{
				mini->s_dup_env[z][mini->taille] = mini->s_export[j];
				mini->taille++;
				j++;
			}
			mini->s_dup_env[z][mini->taille] = '\0';
			return (1);
		}
		z++;
	}
	my_export_bis_bis(mini, cmd, i);
	return (0);
}

int	my_export_bis_bis(t_mini *mini, char **cmd, int i)
{
	int	j;
	int	z;

	z = 0;
	j = 0;
	mini->boolean = 0;
	while (mini->s_dup_env[z][0] != '.')
		z++;
	while (cmd[i][j])
	{
		mini->s_dup_env[z][mini->boolean] = cmd[i][j];
		mini->boolean++;
		j++;
	}
	mini->s_dup_env[z][mini->boolean] = '\0';
	mini->val_env = mini->val_env + 1;
	return (1);
}
