/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_nmbr_line_ter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:38:54 by marvin            #+#    #+#             */
/*   Updated: 2023/07/25 21:38:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	nmbr_char_bis_dquote_bis(char *prompt, t_util *util)
{
	if (prompt[util->i + 1] == '$' && prompt[util->i] != 34
		&& ((prompt[util->i + 2] >= 65 && prompt[util->i + 2] <= 90)
			|| (prompt[util->i + 2] >= 97 && prompt[util->i + 2] <= 122)
			|| (prompt[util->i + 2] >= 48 && prompt[util->i + 2] <= 57)
			|| prompt[util->i + 2] == '?' || prompt[util->i + 2] == '_'))
	{
		util->tab[util->k] = malloc(sizeof(char) * util->j + 1);
		if (!util->tab[util->k])
		{
			util->free = 1;
			return (1);
		}
		util->tab[util->k][util->j] = '\0';
		util->i++;
		util->j++;
		util->j = 0;
		util->k++;
	}
	return (0);
}

int	nmbr_char_bis_dquote_quater(char *prompt, t_util *util)
{
	while ((prompt[util->i] >= 65 && prompt[util->i] <= 90)
		|| (prompt[util->i] >= 97 && prompt[util->i] <= 122)
		|| (prompt[util->i] >= 48 && prompt[util->i] <= 57)
		|| prompt[util->i] == '?' || prompt[util->i] == '_')
	{
		util->i++;
		util->j++;
	}
	util->tab[util->k] = malloc(sizeof(char) * util->j + 1);
	if (!util->tab[util->k])
	{
		util->free = 1;
		return (1);
	}
	util->tab[util->k][util->j] = '\0';
	if (prompt[util->i + 1] != 34 && prompt[util->i + 1] != ' '
		&& prompt[util->i + 1] != '	' && prompt[util->i + 1] != '<'
		&& prompt[util->i + 1] != '>' && prompt[util->i + 1] != '|')
	{
		util->j = 0;
		util->k++;
	}
	return (0);
}

int	nmbr_char_bis_dquote_ter(char *prompt, t_util *util)
{
	if (prompt[util->i] == '?' && ((prompt[util->i + 1] >= 65
				&& prompt[util->i + 1] <= 90) || (prompt[util->i + 1] >= 97
				&& prompt[util->i + 1] <= 122) || (prompt[util->i + 1] >= 48
				&& prompt[util->i + 1] <= 57)))
	{
		util->i++;
		util->j++;
		util->tab[util->k] = malloc(sizeof(char) * util->j + 1);
		if (!util->tab[util->k])
		{
			util->free = 1;
			return (1);
		}
		util->tab[util->k][util->j] = '\0';
		util->j = 0;
		util->k++;
	}
	else
		if (nmbr_char_bis_dquote_quater(prompt, util) == 1)
			return (1);
	return (0);
}

int	alloc_lines_noquotes_bis(char *prompt, t_util *util)
{
	if (prompt[util->i + 1] == '$' && prompt[util->i] != '<'
		&& prompt[util->i] != '>' && prompt[util->i] != '|'
		&& prompt[util->i] != ' ' && prompt[util->i] != '	'
		&& ((prompt[util->i + 2] >= 65 && prompt[util->i + 2] <= 90)
			|| (prompt[util->i + 2] >= 97 && prompt[util->i + 2] <= 122)
			|| (prompt[util->i + 2] >= 48 && prompt[util->i + 2] <= 57)
			|| prompt[util->i + 2] == '?' || prompt[util->i + 2] == '_'))
	{
		util->i++;
		util->j++;
		return (1);
	}
	return (0);
}

int	alloc_lines_noquotes_ter(char *prompt, t_util *util)
{
	util->i++;
	util->j++;
	if (prompt[util->i] == '?' && ((prompt[util->i + 1] >= 65
				&& prompt[util->i + 1] <= 90) || (prompt[util->i + 1] >= 97
				&& prompt[util->i + 1] <= 122) || (prompt[util->i + 1] >= 48
				&& prompt[util->i + 1] <= 57)))
	{
		util->i++;
		util->j++;
		return (1);
	}
	while ((prompt[util->i] >= 65 && prompt[util->i] <= 90)
		|| (prompt[util->i] >= 97 && prompt[util->i] <= 122)
		|| (prompt[util->i] >= 48 && prompt[util->i] <= 57)
		|| prompt[util->i] == '?' || prompt[util->i] == '_')
	{
		util->i++;
		util->j++;
	}
	while (prompt[util->i] == ' ' || prompt[util->i] == '	')
		util->i++;
	return (1);
}
