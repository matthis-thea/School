/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_or_not_builtins.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:55:41 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 12:46:06 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	status_out(pid_t pid, t_mini *mini)
{
	mini->status = 0;
	mini->g_pid_wait = waitpid(pid, &mini->status, WUNTRACED | WCONTINUED);
	if (mini->g_pid_wait == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(mini->status))
		mini->status = WEXITSTATUS(mini->status);
	return ;
}

int	ft_if_builtins_equal_one_other(t_mini *mini)
{
	pid_t	pid;

	pid = 0;
	if (mini->if_build == 1)
		ft_if_equal_builtins(mini, pid);
	else if (mini->if_build == 0)
		ft_not_equal_builtins(mini);
	return (1);
}

int	fork_builtins_else(t_mini *mini, pid_t	pid)
{
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		mini->boolean = ft_if_builtins_one(mini);
		return (0);
	}
	else if (pid > 0)
		status_out(pid, mini);
	return (1);
}

int	ft_if_equal_builtins(t_mini *mini, pid_t	pid)
{
	mini->taille = ft_strlen(mini->s_cmd[0]);
	if (ft_strncmp(mini->s_cmd[0], "exit", ft_strlen("exit")))
		mini->boolean = my_exit(mini->s_cmd, mini);
	if (ft_strncmp(mini->s_cmd[0], "cd", ft_strlen("cd")))
		mini->boolean = my_cd(mini->s_cmd, mini);
	else if (ft_strncmp(mini->s_cmd[0], "echo", ft_strlen("echo")))
		mini->boolean = ft_my_echo(mini->s_cmd, mini);
	else if (ft_strncmp(mini->s_cmd[0], "env", ft_strlen("env")))
		mini->boolean = my_env(mini->s_dup_env, mini->s_cmd);
	else if (ft_strncmp(mini->s_cmd[0], "export", ft_strlen("export")))
		mini->boolean = my_export(mini, mini->s_cmd);
	else if (ft_strncmp(mini->s_cmd[0], "pwd", ft_strlen("pwd")))
		mini->boolean = my_pwd(mini->s_dup_env);
	else if (ft_strncmp(mini->s_cmd[0], "unset", ft_strlen("unset")))
		mini->boolean = my_unset(mini->s_dup_env, mini, mini->s_cmd);
	else
		fork_builtins_else(mini, pid);
	return (1);
}

int	ft_not_equal_builtins(t_mini *mini)
{
	int	i;

	i = 0;
	mini->z = 0;
	mini->j = 0;
	mini->cmd_p = alloc_tab_pipes(mini->cmd_p);
	mini->cmd_p = place_tab_pipes(mini->cmd_p, mini->s_cmd, mini, i);
	if (mini->status_pipes == 1)
		redirection_pipes(mini->cmd_p, mini);
	else
		pipeline(mini->cmd_p, mini);
	return (1);
}
