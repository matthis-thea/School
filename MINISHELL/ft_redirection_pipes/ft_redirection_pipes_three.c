/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_pipes_three.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:55:41 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 12:17:21 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	stdout_i_trois(char ***cmd, int *i, t_mini *mini, int j)
{
	int	out;

	(*i)++;
	out = open(cmd[*i][0], O_CREAT | O_WRONLY, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (((access(cmd[*i][0], R_OK)
			&& access(cmd[*i][0], W_OK)) == 0) && out > 0)
	{
		dup2(out, 1);
		dup2(out, 2);
		close(out);
		ft_exec_pipelines(cmd[j], mini);
		return (1);
	}
	else
	{
		printf("File %s is not writeable or forbid location\n", cmd[*i][0]);
		return (0);
	}
}

int	stdin_i_trois(char ***cmd, int	*i, t_mini *mini, int j)
{
	int	in;

	(*i)++;
	in = open(cmd[*i][0], O_RDONLY);
	if (access(cmd[*i][0], F_OK) == 0 && in > 0
		&& access(cmd[*i][0], R_OK) == 0)
	{
		if (fork_stout(in, cmd[j], mini) == 0)
			return (0);
		close(in);
		return (1);
	}
	else
	{
		printf("File %s is not readable or doesn't existing !\n", cmd[*i][0]);
		return (0);
	}
}

int	stdin_append_trois(char ***cmd, int *i, t_mini *mini, int j)
{
	int	out;

	(*i)++;
	out = open(cmd[*i][0], O_CREAT | O_WRONLY
			| O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	dup2(out, 1);
	dup2(out, 2);
	close(out);
	ft_exec_pipelines(cmd[j], mini);
	return (1);
}

int	stdin_normal(char ***cmd, int *i, int j, t_mini *mini)
{
	(*i)++;
	if (access(cmd[*i][0], F_OK) != 0)
		stdin_normal_files_not(cmd, i, j, mini);
	else if (access(cmd[*i][0], F_OK) == 0)
		stdin_normal_files(cmd, i, j, mini);
	else
	{
		printf("File %s is not readable or writeable ", cmd[*i][0]);
		printf("or it's impossible to open this file\n");
		return (0);
	}
	return (1);
}

int	stdin_double_normal(char ***cmd, int *i, int j, t_mini *mini)
{
	int		out;

	(*i)++;
	out = open(cmd[*i][0], O_CREAT | O_WRONLY
			| O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (access(cmd[*i][0], W_OK) == 0
			&& out > 0 && access(cmd[*i][0], R_OK) == 0)
	{
		mini->error = fork_stdin(mini->stdint_red, out, cmd[j], mini);
		if (mini->error == 0)
			return (0);
		mini->stdint_red = mini->fd[0];
	}
	return (1);
}
