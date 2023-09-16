/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:59:44 by mthea             #+#    #+#             */
/*   Updated: 2023/08/21 12:48:44 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

char	**ft_free_malloc_mini(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	***ft_free_malloc_mini_triple(char ***tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

void	ft_free_all(t_mini *mini, t_util *util, char *prompt)
{
	free_end(util, prompt);
	free(mini->aff_exec);
	free(mini->str);
	free(mini->s_export);
	ft_free_malloc_mini_triple(mini->cmd_p);
	ft_free_malloc_mini(mini->s_env);
	ft_free_malloc_mini(mini->s_cmd);
	ft_free_malloc_mini(mini->s_dup_env);
}
