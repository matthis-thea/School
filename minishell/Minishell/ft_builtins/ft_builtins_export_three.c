/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_export_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:23:26 by mthea             #+#    #+#             */
/*   Updated: 2023/08/18 15:28:14 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

char	*remplissage_bis(t_mini *mini, char **cmd, int i, char *export)
{
	int	j;
	int	z;

	z = 0;
	j = 0;
	while (cmd[i][j])
	{
		if (cmd[i][j] == '=')
		{
			j++;
			while (cmd[i][j])
				export[z++] = cmd[i][j++];
			export[z] = '\0';
			mini->export_i = z;
			export = remplissage(mini, cmd, i, export);
			return (export);
		}
		j++;
	}
	return (export);
}

char	*alloc_rem(char *export)
{
	export = malloc(sizeof(char) * 400);
	if (!export)
		return (0);
	return (export);
}

char	*cmd_after(t_mini *mini, char **cmd, int i)
{
	char	*export;
	int		j;

	j = 0;
	export = NULL;
	export = alloc_rem(export);
	mini->boolean = 0;
	while (cmd[i][j])
	{
		if (cmd[i][j] == '=')
		{
			if (cmd[i][j + 1])
				export = remplissage_bis(mini, cmd, i, export);
			else
			{
				i++;
				mini->export_i = 0;
				export = remplissage(mini, cmd, i, export);
				return (export);
			}
			j++;
		}
		j++;
	}
	return (export);
}
