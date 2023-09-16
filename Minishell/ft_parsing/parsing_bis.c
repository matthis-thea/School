/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:01:53 by marvin            #+#    #+#             */
/*   Updated: 2023/07/04 20:01:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	if_dollars_bis(char *prompt, t_util *util)
{
	while ((prompt[util->i] > 65
			&& prompt[util->i] <= 90) || (prompt[util->i] >= 97
			&& prompt[util->i] <= 122) || (prompt[util->i] >= 48
			&& prompt[util->i] <= 57) || prompt[util->i] == '?'
		|| prompt[util->i] == '_')
		util->i++;
	if (prompt[util->i] != '\0' && prompt[util->i] != ' '
		&& prompt[util->i] != '	' && prompt[util->i] != '<'
		&& prompt[util->i] != '>' && prompt[util->i] != '|')
		util->j++;
}

void	if_dollars(char *prompt, t_util *util)
{
	if (prompt[util->i] == '$'
		&& ((prompt[util->i + 1] >= 65 && prompt[util->i + 1] <= 90)
			|| (prompt[util->i + 1] >= 97 && prompt[util->i + 1] <= 122)
			|| (prompt[util->i + 1] >= 48 && prompt[util->i + 1] <= 57)
			|| prompt[util->i + 1] == '?' || prompt[util->i + 1] == '_'))
	{
		if (prompt[util->i - 1] != ' '
			&& prompt[util->i - 1] != '	' && prompt[util->i - 1] != '<'
			&& prompt[util->i - 1] != '>' && prompt[util->i - 1] != '|')
			util->j++;
		util->i++;
		if (prompt[util->i] == '?' && ((prompt[util->i + 1] >= 65
					&& prompt[util->i + 1] <= 90) || (prompt[util->i + 1] >= 97
					&& prompt[util->i + 1] <= 122) || (prompt[util->i + 1] >= 48
					&& prompt[util->i + 1] <= 57)))
			util->j++;
		if_dollars_bis(prompt, util);
	}
	else
		util->i++;
}

void	if_dollars_inquote_bis(char *prompt, t_util *util)
{
	while ((prompt[util->i] > 65
			&& prompt[util->i] <= 90) || (prompt[util->i] >= 97
			&& prompt[util->i] <= 122) || (prompt[util->i] >= 48
			&& prompt[util->i] <= 57) || prompt[util->i] == '?'
		|| prompt[util->i] == '_')
		util->i++;
	if (prompt[util->i] != 34)
		util->j++;
}

void	if_dollars_inquote(char *prompt, t_util *util)
{
	while (prompt[util->i] != 34)
	{
		if (prompt[util->i] == '$'
			&& ((prompt[util->i + 1] >= 65 && prompt[util->i + 1] <= 90)
				|| (prompt[util->i + 1] >= 97 && prompt[util->i + 1] <= 122)
				|| (prompt[util->i + 1] >= 48 && prompt[util->i + 1] <= 57)
				|| prompt[util->i + 1] == '?' || prompt[util->i + 1] == '_'))
		{
			util->j++;
			util->i++;
			if (prompt[util->i] == '?' && ((prompt[util->i + 1] >= 65
						&& prompt[util->i + 1] <= 90)
					|| (prompt[util->i + 1] >= 97 && prompt[util->i + 1] <= 122)
					|| (prompt[util->i + 1] >= 48
						&& prompt[util->i + 1] <= 57)))
				util->j++;
			if_dollars_inquote_bis(prompt, util);
		}
		else
			util->i++;
	}
}
