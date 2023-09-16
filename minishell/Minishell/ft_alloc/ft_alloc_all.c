/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:58:52 by mthea             #+#    #+#             */
/*   Updated: 2023/08/20 16:25:34 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	alloc_all(t_util *util, t_mini	*mini, char **env)
{
	mini->bool_main = 1;
	mini->error = 0;
	mini->cd_bool = 1;
	mini->bool_echo = 1;
	mini->boucle = 1;
	mini->error = ft_for_env(env, mini);
	if (!mini->error)
	{
		free(mini);
		free(util);
		return (0);
	}
	alloc_dupli_env(mini);
	duplicate_env(env, mini);
	return (1);
}
