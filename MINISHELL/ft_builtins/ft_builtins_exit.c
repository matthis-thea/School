/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:35:18 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 11:29:32 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

long long int	ft_atoi(const char *thestring)
{
	int	i;
	int	valeur;
	int	moins;

	i = 0;
	valeur = 0;
	moins = 0;
	while ((thestring[i] >= 9 && thestring[i] <= 13) || thestring[i] == 32)
		i++;
	if (thestring[i] == 43 || thestring[i] == 45)
	{
		if (thestring[i] == 45)
			moins++;
		i++;
	}
	while (thestring[i] && (thestring[i] >= 48 && thestring[i] <= 57))
	{
		valeur = ((valeur * 10) + (thestring[i] - 48));
		i++;
	}
	if (moins)
		valeur = -valeur;
	if (!(thestring[i] >= 48 && thestring[i] <= 57) && valeur == 0)
		return (0);
	return (valeur);
}

void	exit_equal_two(long long int return_code, char **cmd, t_mini *mini)
{
	printf("exit\n");
	return_code = ft_atoi(cmd[1]);
	if (return_code >= 0 && return_code <= 127)
		mini->status = return_code;
	else
		mini->status = return_code % 256;
}

void	exit_hello(t_mini *mini)
{
	printf("exit\n");
	mini->status = 255;
}

void	my_exit_bis(char **cmd, t_mini *mini, int i, long long int return_code)
{
	if (i == 1)
	{
		printf("exit\n");
		mini->status = 0;
	}
	else if (i > 2 && !mini->exit_num_bool)
	{
		printf("exit\n");
		printf("minishell: exit: too many arguments\n");
		mini->status = 1;
	}
	else if (ft_strncmp(&cmd[1][0], "hello", ft_strlen(&cmd[1][0])))
		exit_hello(mini);
	else if (mini->exit_num_bool)
	{
		printf("exit\n");
		printf("minishell: exit: numerics arguments only\n");
		mini->status = 2;
	}
	else if (i == 2)
		exit_equal_two(return_code, cmd, mini);
	else
		printf("exit\n");
}

int	my_exit(char **cmd, t_mini *mini)
{
	long long int	return_code;
	int				i;
	int				j;

	i = 1;
	j = 0;
	mini->final_exit = 0;
	mini->exit_num_bool = 0;
	return_code = 0;
	while (cmd[i])
	{
		while (cmd[i][j])
		{
			if (i == 1 && ((cmd[i][j] >= 'A' && cmd[i][j] <= 'Z')
			|| (cmd[i][j] >= 'a' && cmd[i][j] <= 'z')))
				mini->exit_num_bool = 1;
			j++;
		}
		i++;
		j = 0;
	}
	my_exit_bis(cmd, mini, i, return_code);
	mini->boucle = 0;
	exit(mini->status);
	return (0);
}
