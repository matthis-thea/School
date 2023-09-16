/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipelines_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:23:26 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 11:54:01 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	ft_if_builtins_one_pipes(char **cmd, t_mini *mini)
{
	int	j;

	j = 0;
	mini->error = ft_path_exist(mini);
	if (!mini->error)
		return (0);
	while (mini->s_env[j])
	{
		mini->aff_exec = ft_strjoin(mini->s_env[j], *cmd);
		mini->boolean = execve(mini->aff_exec, cmd, NULL);
		if (mini->boolean == -1)
			mini->boolean = execve(*cmd, cmd, NULL);
		j++;
	}
	return (1);
}

int	ft_exec_pipe(char **cmd, t_mini *mini)
{
	mini->taille = ft_strlen(*cmd);
	if (ft_strncmp(*cmd, "exit", ft_strlen("exit")))
		my_exit(cmd, mini);
	else if (ft_strncmp(*cmd, "cd", ft_strlen("cd")))
		my_cd(cmd, mini);
	else if (ft_strncmp(*cmd, "echo", ft_strlen("echo")))
		ft_my_echo(cmd, mini);
	else if (ft_strncmp(*cmd, "env", ft_strlen("env")))
		my_env(mini->s_dup_env, cmd);
	else if (ft_strncmp(*cmd, "export", ft_strlen("export")))
		my_export(mini, cmd);
	else if (ft_strncmp(*cmd, "pwd", ft_strlen("pwd")))
		my_pwd(mini->s_dup_env);
	else if (ft_strncmp(*cmd, "unset", ft_strlen("unset")))
		my_unset(mini->s_dup_env, mini, cmd);
	else
		ft_if_builtins_one_pipes(cmd, mini);
	return (mini->boolean);
}

int	count(char ***cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}
