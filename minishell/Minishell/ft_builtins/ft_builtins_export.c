/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:23:26 by mthea             #+#    #+#             */
/*   Updated: 2023/08/20 13:01:43 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	m_export_bis(t_mini *mini, char **cmd, int i)
{
	if (i == 1)
		my_env(mini->s_dup_env, cmd);
	else
	{
		i = 0;
		while (cmd[i])
		{
			mini->equal_export = verif_export(cmd, i, mini);
			if (mini->equal_export == 1)
			{
				mini->status = 1;
				printf("export: not valid in this context: %s\n", cmd[i]);
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int	my_export(t_mini *mini, char **cmd)
{
	int	i;

	i = 1;
	mini->equal_export = 0;
	while (cmd[i])
	{
		mini->equal_export = verif_export(cmd, i, mini);
		if (mini->equal_export == 1)
			mini->equal_export = 0;
		else if (ft_cpm_export(cmd[i], '=') > 0)
		{
			mini->boolean = cmd_before(cmd, i, mini);
			mini->s_export = cmd_after(mini, cmd, i);
			my_export_bis(mini, cmd, i);
		}
		i++;
	}
	mini->boolean = m_export_bis(mini, cmd, i);
	if (mini->boolean == 0)
		return (0);
	return (0);
}

int	ft_cpm_export(char *s1, char s2)
{
	size_t				i;

	i = 0;
	while (s1[i] && s1[i] != s2)
		i++;
	if (s1[i] == s2)
		return (2);
	return (0);
}

int	ft_cpm_export_bis(char *s1, char *s2, char s3, int taille)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] != s3 && s2[i] != s3) && i < taille)
		i++;
	if (s1[i - 1] == s2[i])
		return (2);
	return (0);
}

char	*remplissage(t_mini *mini, char **cmd, int i, char *export)
{
	int	z;
	int	taille;
	int	j;

	z = 0;
	j = mini->export_i;
	while (cmd[i])
	{
		while (mini->s_dup_env[z][0] != '.')
		{
			taille = cmd_before(mini->s_dup_env, z, mini);
			if (ft_strncmp(&cmd[i][1], mini->s_dup_env[z], taille - 1))
			{
				if (cmd[i][cmd_before(mini->s_dup_env, z, mini)])
					return (export);
				while (mini->s_dup_env[z][taille])
					export[j++] = mini->s_dup_env[z][taille++];
				export[j] = '\0';
			}
			z++;
		}
		i++;
		z = 0;
	}
	return (export);
}
