/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:55:41 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 11:51:33 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	else_normal(char ***cmd, int *i, int *j, t_mini *mini)
{
	if (cmd[*i + 1][0][0] == '>' || cmd[*i + 1][0][0] == '<')
	{
		*j = *i;
	}
	else
	{
		pipe(mini->fd);
		fork_stdin(mini->stdint_red, mini->fd[1], cmd[*i], mini);
		close(mini->fd[1]);
		mini->stdint_red = mini->fd[0];
	}
	return (1);
}

void	stdout_trois_bis(pid_t pid, t_mini *mini)
{
	status_out(pid, mini);
}

int	stdout_trois(char ***cmd, int *i, t_mini *mini)
{
	char	*prompt;
	int		out;
	pid_t	pid;
	char	*fn;

	(*i)++;
	prompt = "m";
	fn = "/tmp/filetmp.txt";
	out = open(fn, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	pid = fork();
	if (pid == 0)
	{
		while (!ft_strncmp(prompt, cmd[*i][0], ft_strlen(&cmd[*i][0][0])))
		{
			prompt = readline("\033[0;32hheredoc<< \033[0m");
			write(out, prompt, ft_strlen(prompt));
			write(out, "\n", ft_strlen("\n"));
		}
		fork_stout(out, cmd[*i - 2], mini);
		exit(1);
	}
	else if (pid > 0)
		stdout_trois_bis(pid, mini);
	return (1);
}

int	redirection_pipes(char **cmd[], t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mini->count_pipes = count(cmd);
	while (i < mini->count_pipes - 1)
	{
		if (cmd[i][0][0] == '>' && !cmd[i][0][1])
			stdin_normal(cmd, &i, j, mini);
		else if (cmd[i][0][0] == '<' && !cmd[i][0][1])
			stdin_i_trois(cmd, &i, mini, j);
		else if (cmd[i][0][0] == '>' && cmd[i][0][1] == '>')
			stdin_double_normal(cmd, &i, j, mini);
		else if (cmd[i][0][0] == '<' && cmd[i][0][1] == '<')
			stdout_trois(cmd, &i, mini);
		else
			else_normal(cmd, &i, &j, mini);
		i++;
	}
	return (1);
}
