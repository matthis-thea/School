/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_pipes_four.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:55:41 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 12:17:41 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	stdin_normal_files_not(char ***cmd, int *i, int j, t_mini *mini)
{
	int	out;

	out = open(cmd[*i][0], O_CREAT
			| O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (access(cmd[*i][0], W_OK) == 0
			&& access(cmd[*i][0], R_OK) == 0 && out > 0)
	{
		mini->error = fork_stdin(mini->stdint_red, out, cmd[j], mini);
		if (mini->error == 0)
			return (0);
	}
	else
	{
		printf("File %s is not readable or writeable ", cmd[*i][0]);
		printf("or it's impossible to open this file\n");
	}
	return (1);
}

int	stdin_normal_files(char ***cmd, int *i, int j, t_mini *mini)
{
	int	out;

	out = open(cmd[*i][0], O_TRUNC
			| O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (access(cmd[*i][0], W_OK) == 0
			&& access(cmd[*i][0], R_OK) == 0 && out > 0)
	{
		mini->error = fork_stdin(mini->stdint_red, out, cmd[j], mini);
		if (mini->error == 0)
			return (0);
	}
	else
	{
		printf("File %s is not readable or writeable ", cmd[*i][0]);
		printf("or it's impossible to open this file\n");
	}
	return (1);
}
