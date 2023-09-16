/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_tab_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:45:25 by thib              #+#    #+#             */
/*   Updated: 2023/08/20 16:19:53 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	tab_affect(char *prompt, t_util *util)
{
	util->tab[util->k][util->j] = prompt[util->i];
	util->j++;
	util->i++;
}

void	push_lines_command_bis(char *prompt, t_util *util)
{
	if (prompt[util->i] == 39)
	{
		util->i++;
		while (prompt[util->i] != 39)
			tab_affect(prompt, util);
		util->i++;
	}
	else if (prompt[util->i] == 34)
	{
		util->i++;
		while (prompt[util->i] != 34)
			tab_affect(prompt, util);
		util->i++;
	}
	else
		tab_affect(prompt, util);
}

int	args_bis_dquote(char *prompt, t_util *util)
{
	while (prompt[util->i] != 34)
	{
		args_bis_dquote_bis(prompt, util);
		if (prompt[util->i] == '$'
			&& ((prompt[util->i + 1] >= 65 && prompt[util->i + 1] <= 90)
				|| (prompt[util->i + 1] >= 97 && prompt[util->i + 1] <= 122)
				|| (prompt[util->i + 1] >= 48 && prompt[util->i + 1] <= 57)
				|| prompt[util->i + 1] == '?' || prompt[util->i + 1] == '_'))
		{
			if (prompt[util->i - 1] == ' ')
			{
				util->tab[util->k][util->j] = ' ';
				util->j++;
			}
			args_bis_dquote_ter(prompt, util);
		}
		else
		{
			util->tab[util->k][util->j] = prompt[util->i];
			util->i++;
			util->j++;
		}
	}
	return (0);
}

int	push_arg_noquotes(char *prompt, t_util *util)
{
	if (push_arg_noquotes_bis(prompt, util) == 1)
		return (1);
	if (prompt[util->i] == '$'
		&& ((prompt[util->i + 1] >= 65 && prompt[util->i + 1] <= 90)
			|| (prompt[util->i + 1] >= 97 && prompt[util->i + 1] <= 122)
			|| (prompt[util->i + 1] >= 48 && prompt[util->i + 1] <= 57)
			|| prompt[util->i + 1] == '?' || prompt[util->i + 1] == '_'))
	{
		if (prompt[util->i - 1] == ' ')
		{
			util->tab[util->k][util->j] = ' ';
			util->j++;
		}
		if (push_arg_noquotes_ter(prompt, util) == 1)
			return (1);
	}
	else
	{
		util->tab[util->k][util->j] = prompt[util->i];
		util->i++;
		util->j++;
	}
	return (0);
}

int	push_args_bis(char *prompt, t_util *util)
{
	if (prompt[util->i - 1] == ' ' && util->k > 1 && prompt[util->i] != '-')
	{
		util->tab[util->k][util->j] = ' ';
		util->j++;
	}
	if (prompt[util->i] == 39)
		push_args_ter(prompt, util);
	else if (prompt[util->i] == 34)
	{
		util->i++;
		if (args_bis_dquote(prompt, util) == 1)
			return (1);
		util->i++;
		if (prompt[util->i] == 34 && prompt[util->i + 1] == '$')
		{
			util->j = 0;
			util->k++;
		}
	}
	else
		if (push_arg_noquotes(prompt, util) == 1)
			return (1);
	return (0);
}
