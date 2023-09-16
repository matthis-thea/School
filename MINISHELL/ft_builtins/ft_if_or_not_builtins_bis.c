/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_or_not_builtins_bis.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:55:41 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 11:38:36 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	ft_verif_if_pipes(t_mini *mini)
{
	int	i;
	int	nb_return;

	i = 0;
	nb_return = 0;
	nb_return = ft_verif_if_pipes_bis(mini, i);
	return (nb_return);
}

int	ft_verif_if_pipes_bis(t_mini *mini, int i)
{
	while (mini->s_cmd[i])
	{
		if (mini->pipe_quote == 1)
			return (1);
		if (mini->s_cmd[i][0] == '|' || mini->s_cmd[i][0] == '<'
			|| mini->s_cmd[i][0] == '>')
			return (0);
		i++;
	}
	return (1);
}

int	ft_if_builtins_one(t_mini *mini)
{
	int	i;

	i = 0;
	mini->error = ft_path_exist(mini);
	if (!mini->error)
		exit(127);
	while (mini->s_env[i])
	{
		mini->aff_exec = ft_strjoin(mini->s_env[i], mini->s_cmd[0]);
		mini->boolean = execve(mini->aff_exec, mini->s_cmd, NULL);
		if (mini->boolean == -1)
			execve(mini->s_cmd[0], mini->s_cmd, NULL);
		i++;
	}
	if (mini->s_cmd[0][0] >= 21 && mini->s_cmd[0][0] <= 126)
	{
		printf("Minishell: %s: command not found\n", mini->s_cmd[0]);
		mini->status = 127;
		exit(127);
	}
	else
		exit(0);
}
