/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_pipes_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:55:41 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 12:48:28 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	ft_if_buil_one_pipes(char **cmd, t_mini *mini)
{
	int	j;

	j = 0;
	mini->error = ft_path_exist(mini);
	if (!mini->error)
		return (0);
	while (mini->s_env[j])
	{
		mini->aff_exec = ft_strjoin(mini->s_env[j], cmd[0]);
		mini->boolean = execve(mini->aff_exec, cmd, NULL);
		if (mini->boolean == -1)
			mini->boolean = execve(cmd[0], cmd, NULL);
		j++;
	}
	printf("Minishell command not found %s\n", cmd[0]);
	mini->status = 1;
	return (0);
}

int	ft_exec_pipelines(char **cmd, t_mini *mini)
{
	int	i;

	i = 0;
	mini->taille = ft_strlen(cmd[i]);
	if (ft_strncmp(cmd[i], "exit", ft_strlen("exit")))
		return (0);
	else if (ft_strncmp(cmd[i], "cd", ft_strlen("cd")))
		my_cd(cmd, mini);
	else if (ft_strncmp(cmd[i], "echo", ft_strlen("echo")))
		ft_my_echo(cmd, mini);
	else if (ft_strncmp(cmd[i], "env", ft_strlen("env")))
		my_env(mini->s_dup_env, cmd);
	else if (ft_strncmp(cmd[i], "export", ft_strlen("export")))
		my_export(mini, cmd);
	else if (ft_strncmp(cmd[i], "pwd", ft_strlen("pwd")))
		my_pwd(mini->s_dup_env);
	else if (ft_strncmp(cmd[i], "unset", ft_strlen("unset")))
		my_unset(mini->s_dup_env, mini, cmd);
	else
		ft_if_buil_one_pipes(cmd, mini);
	exit(EXIT_SUCCESS);
}

int	fork_stdin(int in, int out, char **cmd, t_mini *mini)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (in != 0)
		{
			dup2 (in, 0);
			close (in);
		}
		if (out != 1)
		{
			dup2 (out, 1);
			close (out);
		}
		mini->error_pipes = ft_exec_pipelines(cmd, mini);
		if (mini->error_pipes == 0)
			return (0);
	}
	else if (pid > 0)
		stdout_trois_bis(pid, mini);
	return (1);
}

int	fork_stout(int test3, char **cmd, t_mini *mini)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(test3, 0);
		close(test3);
		mini->error_pipes = ft_exec_pipelines(cmd, mini);
		if (mini->error_pipes == 0)
			return (0);
	}
	else if (pid > 0)
		stdout_trois_bis(pid, mini);
	return (1);
}
