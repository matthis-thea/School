/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quater.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:48:53 by tserdet           #+#    #+#             */
/*   Updated: 2023/08/20 16:20:04 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	alloc_nmbr_char_ter(char *prompt, t_util *util)
{
	util->i++;
	while (prompt[util->i] != 39)
	{
		util->i++;
		util->j++;
	}
	util->i++;
}

void	push_args_ter(char *prompt, t_util *util)
{
	util->i++;
	while (prompt[util->i] != 39)
	{
		if (prompt[util->i] == '$')
			util->intab[util->k] = 1;
		util->tab[util->k][util->j] = prompt[util->i];
		util->i++;
		util->j++;
	}
	util->i++;
}

void	args_bis_dquote_quater(char *prompt, t_util *util)
{
	while ((prompt[util->i] >= 65 && prompt[util->i] <= 90)
		|| (prompt[util->i] >= 97 && prompt[util->i] <= 122)
		|| (prompt[util->i] >= 48 && prompt[util->i] <= 57)
		|| prompt[util->i] == '?' || prompt[util->i] == '_')
	{
		util->tab[util->k][util->j] = prompt[util->i];
		util->i++;
		util->j++;
	}
	if (prompt[util->i + 1] != 34 && prompt[util->i + 1] != ' '
		&& prompt[util->i + 1] != '	' && prompt[util->i + 1] != '<'
		&& prompt[util->i + 1] != '>' && prompt[util->i + 1] != '|')
	{
		util->j = 0;
		util->k++;
	}
}
