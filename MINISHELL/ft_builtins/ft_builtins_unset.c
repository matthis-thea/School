/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:38:24 by haze              #+#    #+#             */
/*   Updated: 2023/08/20 13:01:55 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	my_unset(char **cmd, t_mini *mini, char **s_cmd)
{
	char	**str;

	str = NULL;
	str = alloc_dupli_unset(str);
	duplicate_unset(str, cmd);
	verification_unset(str, mini, s_cmd);
	duplicate_unset_rev(str, cmd, mini);
	return (0);
}

char	**alloc_dupli_unset(char **str)
{
	int	i;

	i = 0;
	str = malloc(sizeof(char *) * 200);
	if (str == NULL)
		return (0);
	while (i < 200)
	{
		str[i] = malloc(sizeof(char) * 200);
		if (str[i] == NULL)
		{
			ft_free_malloc(str, i);
			return (0);
		}
		i++;
	}
	return (str);
}

int	duplicate_unset(char **str, char **cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		while (cmd[i][j])
		{
			str[i][j] = cmd[i][j];
			j++;
		}
		str[i][j] = '\0';
		i++;
		j = 0;
	}
	while (i < 200)
	{
		str[i][0] = ' ';
		i++;
	}	
	str[i] = NULL;
	return (1);
}

int	verification_unset(char **str, t_mini *mini, char **s_cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s_cmd[i])
	{
		if (ft_cpm_export(s_cmd[i], '=') == 0)
		{
			while (str[j])
			{
				mini->boolean = ft_strlen(s_cmd[i]);
				if (ft_strncmp(s_cmd[i], str[j], mini->boolean) > 0)
					str[j][0] = '\0';
				j++;
			}
		}
		i++;
		j = 0;
	}
	return (1);
}

int	duplicate_unset_rev(char **str, char **cmd, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i][0] == '\0')
		{
			mini->val_env = mini->val_env - 1;
			i++;
		}
		else
			cmd[j++] = str[i++];
	}
	while (j < 200)
		cmd[j++][0] = '.';
	cmd[j] = NULL;
	return (1);
}
