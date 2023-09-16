/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:53:47 by mthea             #+#    #+#             */
/*   Updated: 2023/08/18 16:04:01 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	ft_for_env(char **env, t_mini *mini)
{
	int		i;
	int		j;
	char	*resultat;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i][j] == 'P' && env[i][j + 1] == 'A' && env[i][j + 2] == 'T'
		&& env[i][j + 3] == 'H')
		{
			resultat = &env[i][j + 5];
			mini->s_env = ft_split(resultat, ':');
			if (!mini->s_env)
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

int	duplicate_env(char **env, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		while (env[i][j])
		{
			mini->s_dup_env[i][j] = env[i][j];
			j++;
		}
		mini->s_dup_env[i][j] = '\0';
		i++;
		j = 0;
	}
	mini->val_env = i;
	while (i < 200)
	{
		mini->s_dup_env[i][0] = '.';
		i++;
	}	
	mini->s_dup_env[i] = NULL;
	return (1);
}

int	alloc_dupli_env(t_mini *mini)
{
	int	i;

	i = 0;
	mini->s_dup_env = malloc(sizeof(char *) * 200);
	if (mini->s_dup_env == NULL)
		return (0);
	while (i < 200)
	{
		mini->s_dup_env[i] = malloc(sizeof(char) * 200);
		if (mini->s_dup_env[i] == NULL)
		{
			ft_free_malloc(mini->s_dup_env, i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_path_exist(t_mini *mini)
{
	int		i;
	int		j;
	char	*resultat;

	i = 0;
	j = 0;
	while (mini->s_dup_env[i])
	{
		if (mini->s_dup_env[i][j] == 'P'
		&& mini->s_dup_env[i][j + 1] == 'A'
		&& mini->s_dup_env[i][j + 2] == 'T'
		&& mini->s_dup_env[i][j + 3] == 'H')
		{
			resultat = &mini->s_dup_env[i][j + 5];
			mini->s_env = ft_split(resultat, ':');
			if (!mini->s_env)
				return (0);
			return (1);
		}
		i++;
	}
	printf("La commande n'a pas pu être trouvée car");
	printf("la variable d'environnement PATH est inexistante\n");
	return (0);
}
