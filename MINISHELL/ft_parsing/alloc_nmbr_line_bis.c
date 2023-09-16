/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_nmbr_line_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 09:56:19 by thib              #+#    #+#             */
/*   Updated: 2023/08/20 16:19:36 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	alloc_lines_command_bis(char *prompt, t_util *util)
{
	if (prompt[util->i] == 39)
	{
		util->i++;
		while (prompt[util->i] != 39)
		{
			util->j++;
			util->i++;
		}
		util->i++;
	}
	else if (prompt[util->i] == 34)
	{
		util->i++;
		while (prompt[util->i] != 34)
		{
			util->j++;
			util->i++;
		}
			util->i++;
	}
	else
	{
		util->j++;
		util->i++;
	}
}

int	nmbr_char_bis_dquote(char *prompt, t_util *util)
{
	while (prompt[util->i] != 34)
	{
		if (nmbr_char_bis_dquote_bis(prompt, util) == 1)
			return (1);
		if (prompt[util->i] == '$'
			&& ((prompt[util->i + 1] >= 65 && prompt[util->i + 1] <= 90)
				|| (prompt[util->i + 1] >= 97 && prompt[util->i + 1] <= 122)
				|| (prompt[util->i + 1] >= 48 && prompt[util->i + 1] <= 57)
				|| prompt[util->i + 1] == '?' || prompt[util->i + 1] == '_'))
		{
			if (prompt[util->i - 1] == ' ' && util->j > 3)
				util->j++;
			util->i++;
			util->j++;
			if (nmbr_char_bis_dquote_ter(prompt, util) == 1)
				return (1);
		}
		else
		{
			util->i++;
			util->j++;
		}
	}
	return (0);
}

int	alloc_lines_noquotes(char *prompt, t_util *util)
{
	if (alloc_lines_noquotes_bis(prompt, util) == 1)
		return (1);
	if (prompt[util->i] == '$'
		&& ((prompt[util->i + 1] >= 65 && prompt[util->i + 1] <= 90)
			|| (prompt[util->i + 1] >= 97 && prompt[util->i + 1] <= 122)
			|| (prompt[util->i + 1] >= 48 && prompt[util->i + 1] <= 57)
			|| prompt[util->i + 1] == '?' || prompt[util->i + 1] == '_'))
	{
		if (alloc_lines_noquotes_ter(prompt, util) == 1)
			return (1);
	}
	else
	{
		util->i++;
		util->j++;
	}
	return (0);
}

int	alloc_nmbr_char_bis(char *prompt, t_util *util)
{
	if (prompt[util->i - 1] == ' ' && util->k > 1 && prompt[util->i] != '-')
		util->j++;
	if (prompt[util->i] == 39)
		alloc_nmbr_char_ter(prompt, util);
	else if (prompt[util->i] == 34)
	{
		util->i++;
		if (nmbr_char_bis_dquote(prompt, util) == 1)
			return (1);
		util->i++;
		if (prompt[util->i] == 34 && prompt[util->i + 1] == '$')
		{
			util->j = 0;
			util->k++;
		}
	}
	else
		if (alloc_lines_noquotes(prompt, util) == 1)
			return (1);
	return (0);
}
