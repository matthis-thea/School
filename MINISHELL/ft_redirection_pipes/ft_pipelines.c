/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipelines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:23:26 by mthea             #+#    #+#             */
/*   Updated: 2023/08/20 14:15:24 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	pipeline_bis(char ***cmd, t_mini *mini, int fd[], int i)
{
	pid_t	pid;
	int		j;

	j = 0;
	while (*cmd != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			if (*(cmd + 1))
				dup2(fd[j + 1], 1);
			if (j != 0)
				dup2(fd[j - 2], 0);
			while (i < 2 * mini->cmd_len)
				close(fd[i++]);
			if (ft_exec_pipe(*cmd, mini) == 2)
				exit(1);
			exit(1);
		}
		else if (pid < 0)
			status_out(pid, mini);
		cmd++;
		j += 2;
		i = 0;
	}
}

void	wait_pipeline(int fd[], int i, t_mini *mini)
{
	i = 0;
	while (i < 2 * mini->cmd_len)
		close(fd[i++]);
	i = 0;
	while (i++ < mini->cmd_len)
		wait(NULL);
}

void	pipeline(char ***cmd, t_mini *mini)
{
	int	*fd;
	int	i;

	i = 0;
	fd = malloc(2 * count(cmd) * sizeof(int));
	if (!fd)
		return ;
	mini->cmd_len = count(cmd);
	while (i < mini->cmd_len)
	{
		if (pipe(fd + i * 2) < 0)
			exit(EXIT_FAILURE);
		i++;
	}
	i = 0;
	pipeline_bis(cmd, mini, fd, i);
	wait_pipeline(fd, i, mini);
	return ;
}

char	***alloc_tab_pipes(char ***cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	cmd = malloc(100 * sizeof(char *));
	while (i < 100)
	{
		cmd[i] = malloc(100 * sizeof(char **));
		while (j < 100)
		{
			cmd[i][j] = malloc(100 * sizeof(char ***));
			j++;
		}
		j = 0;
		i++;
	}
	return (cmd);
}

char	***place_tab_pipes(char ***cmd, char **ls, t_mini *mini, int i)
{
	while (ls[mini->j])
	{
		if (ls[mini->j][0] == '<' || ls[mini->j][0] == '>')
		{
			mini->status_pipes = 1;
			cmd[i++][mini->z] = NULL;
			cmd[i][0] = ls[mini->j];
			cmd[i++][1] = NULL;
			mini->j++;
			mini->z = 0;
		}
		else if (ls[mini->j][0] == '|')
		{
			cmd[i++][mini->z] = NULL;
			mini->j++;
			mini->z = 0;
		}
		cmd[i][mini->z++] = ls[mini->j++];
	}
	cmd[i][mini->z] = NULL;
	cmd[i + 1] = NULL;
	return (cmd);
}
