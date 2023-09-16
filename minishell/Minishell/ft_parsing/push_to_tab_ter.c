/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_tab_ter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:39:57 by marvin            #+#    #+#             */
/*   Updated: 2023/07/27 09:39:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	args_bis_dquote_bis(char *prompt, t_util *util)
{
	if (prompt[util->i + 1] == '$' && prompt[util->i] != 34
		&& ((prompt[util->i + 2] >= 65 && prompt[util->i + 2] <= 90)
			|| (prompt[util->i + 2] >= 97 && prompt[util->i + 2] <= 122)
			|| (prompt[util->i + 2] >= 48 && prompt[util->i + 2] <= 57)
			|| prompt[util->i + 2] == '?' || prompt[util->i + 2] == '_'))
	{
		util->tab[util->k][util->j] = prompt[util->i];
		util->i++;
		util->j++;
		util->j = 0;
		util->k++;
	}
	return (0);
}

int	args_bis_dquote_ter(char *prompt, t_util *util)
{
	util->tab[util->k][util->j] = prompt[util->i];
	util->i++;
	util->j++;
	if (prompt[util->i] == '?' && ((prompt[util->i + 1] >= 65
				&& prompt[util->i + 1] <= 90) || (prompt[util->i + 1] >= 97
				&& prompt[util->i + 1] <= 122) || (prompt[util->i + 1] >= 48
				&& prompt[util->i + 1] <= 57)))
	{
		util->tab[util->k][util->j] = prompt[util->i];
		util->i++;
		util->j++;
		util->j = 0;
		util->k++;
	}
	else
		args_bis_dquote_quater(prompt, util);
	return (0);
}

int	push_arg_noquotes_bis(char *prompt, t_util *util)
{
	if (prompt[util->i + 1] == '$' && prompt[util->i] != '<'
		&& prompt[util->i] != '>' && prompt[util->i] != '|'
		&& prompt[util->i] != ' ' && prompt[util->i] != '	'
		&& ((prompt[util->i + 2] >= 65 && prompt[util->i + 2] <= 90)
			|| (prompt[util->i + 2] >= 97 && prompt[util->i + 2] <= 122)
			|| (prompt[util->i + 2] >= 48 && prompt[util->i + 2] <= 57)
			|| prompt[util->i + 2] == '?' || prompt[util->i + 2] == '_'))
	{
		util->tab[util->k][util->j] = prompt[util->i];
		util->i++;
		util->j++;
		return (1);
	}
	return (0);
}

int	push_arg_noquotes_ter(char *prompt, t_util *util)
{
	util->tab[util->k][util->j] = prompt[util->i];
	util->i++;
	util->j++;
	if (prompt[util->i] == '?' && ((prompt[util->i + 1] >= 65
				&& prompt[util->i + 1] <= 90) || (prompt[util->i + 1] >= 97
				&& prompt[util->i + 1] <= 122) || (prompt[util->i + 1] >= 48
				&& prompt[util->i + 1] <= 57)))
	{
			util->tab[util->k][util->j] = prompt[util->i];
			util->i++;
			util->j++;
		return (1);
	}
	while ((prompt[util->i] >= 65 && prompt[util->i] <= 90)
		|| (prompt[util->i] >= 97 && prompt[util->i] <= 122)
		|| (prompt[util->i] >= 48 && prompt[util->i] <= 57)
		|| prompt[util->i] == '?' || prompt[util->i] == '_')
	{
		util->tab[util->k][util->j] = prompt[util->i];
		util->i++;
		util->j++;
	}
	while (prompt[util->i] == ' ' || prompt[util->i] == '	')
		util->i++;
	return (1);
}
