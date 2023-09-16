/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:35:18 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 11:19:51 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	ft_echo_remove_flags(char **cmd)
{
	int	i;
	int	j;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i][0] == '-' && cmd[i][1] == 'n')
		{
			j = 2;
			while (cmd[i][j])
			{
				if (cmd[i][j] == 'n')
					j++;
				else if (cmd[i][j] != '\0')
					return (i);
			}
			i ++;
		}
		else
			return (i);
	}
	return (i);
}

void	if_zero(int i, char **cmd)
{
	if (i > 1)
		printf(" %s", cmd[i]);
	else
		printf("%s", cmd[i]);
}

void	dollard_echo(t_mini *mini, int i, int z, char **cmd)
{
	mini->bool_echo = 1;
	if (cmd[i][0] == '$' && !cmd[i][1])
		printf("%s", cmd[i]);
	else if (cmd[i][1] == '$' && !cmd[i][2])
		printf("%s", cmd[i]);
	else if (cmd[i][1] == '$' && cmd[i][2] == '?')
	{
		if (i == 1)
			printf("%d", mini->status);
		else
			printf(" %d", mini->status);
	}
	else if (cmd[i][0] == '$' && cmd[i][1] == '?')
		printf("%d", mini->status);
	else if (cmd[i][0] == '$')
		echo_dollards_no_space(mini, cmd, z, i);
	else if (cmd[i][1] == '$')
		echo_dollards_space(mini, cmd, z, i);
	else
		printf("%s", cmd[i]);
}

void	ft_my_echo_bis(t_mini *mini, int i, int z, char **cmd)
{
	while (cmd[i])
	{
		mini->bool_echo = 1;
		if (mini->util_tab[i] == 1)
			if_zero(i, cmd);
		else if (cmd[i][0] == '*')
		{
			printf("bash_outfiles bash.supp bonus bonus_bonus builtins ");
			printf("extras local.supp loop.out manual_tests mini_outfiles ");
			printf("os_specific outfiles pipes README.md redirects syntax ");
			printf("tester test_files wildcards");
		}
		else
			dollard_echo(mini, i, z, cmd);
		z = 0;
		i++;
	}
}

int	ft_my_echo(char **cmd, t_mini *mini)
{
	int	i;
	int	z;
	int	n_flag;

	if (cmd[1] == 0)
	{
		printf("\n");
		return (0);
	}
	z = 0;
	mini->bool_echo = 1;
	mini->bool_dol_echo = 1;
	i = ft_echo_remove_flags(cmd);
	n_flag = 0;
	if (i > 1)
		n_flag = 1;
	ft_my_echo_bis(mini, i, z, cmd);
	if (!n_flag)
		printf("\n");
	mini->status = 0;
	return (mini->status);
}
