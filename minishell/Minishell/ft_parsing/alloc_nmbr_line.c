/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_nmbr_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:10:43 by tserdet           #+#    #+#             */
/*   Updated: 2023/08/20 16:19:43 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	alloc_lines_command(char *prompt, t_util *util)
{
	while (prompt[util->i] == ' ' || prompt[util->i] == '	')
		util->i++;
	while (prompt[util->i] != ' ' && prompt[util->i] != '	'
		&& prompt[util->i] != '\0' && prompt[util->i] != '|'
		&& prompt[util->i] != '<' && prompt[util->i] != '>')
		alloc_lines_command_bis(prompt, util);
	util->tab[util->k] = malloc(sizeof(char) * util->j + 1);
	if (!util->tab[util->k])
		return (1);
	util->tab[util->k][util->j] = '\0';
	util->j = 0;
	util->k++;
	return (0);
}

int	alloc_nmbr_char(char *prompt, t_util *util)
{
	while (prompt[util->i] != '|' && prompt[util->i] != '<'
		&& prompt[util->i] != '>' && prompt[util->i] != '\0'
		&& prompt[util->i] != ' ' && prompt[util->i] != '	')
		if (alloc_nmbr_char_bis(prompt, util) == 1)
			return (1);
	while (prompt[util->i] == ' ' || prompt[util->i] == '	')
		util->i++;
	return (0);
}

int	alloc_lines_arg(char *prompt, t_util *util)
{
	while (prompt[util->i] == ' ' || prompt[util->i] == '	')
		util->i++;
	while (prompt[util->i] != '|' && prompt[util->i] != '<'
		&& prompt[util->i] != '>' && prompt[util->i] != '\0')
	{
		if (alloc_nmbr_char(prompt, util) == 1 && util->free == 1)
			return (1);
		if (util->j == 0)
			util->tab[util->k] = NULL;
		else
		{
			util->tab[util->k] = malloc(sizeof(char) * util->j + 1);
			if (!util->tab[util->k])
				return (1);
			util->tab[util->k][util->j] = '\0';
		}
		util->j = 0;
		util->k++;
	}
	return (0);
}

int	alloc_lines_pipe(char *prompt, t_util *util)
{
	while (prompt[util->i] == '<' || prompt[util->i] == '>'
		|| prompt[util->i] == '|' || prompt[util->i] == '=')
	{
		util->j++;
		util->i++;
	}
	if (util->j == 0)
		util->tab[util->k] = NULL;
	else
	{
		util->tab[util->k] = malloc(sizeof(char) * util->j + 1);
		if (!util->tab[util->k])
			return (1);
		util->tab[util->k][util->j] = '\0';
	}
	util->j = 0;
	util->k++;
	return (0);
}

int	alloc_nmbr_lines(char *prompt, t_util *util)
{
	int		i;

	i = 0;
	while (i < util->list_size)
	{
		util->intab[i] = 0;
		i++;
	}
	while (prompt[util->i] != '\0')
	{
		if (alloc_lines_command(prompt, util) == 1)
			return (1);
		if (alloc_lines_arg(prompt, util) == 1)
			return (1);
		if (alloc_lines_pipe(prompt, util) == 1)
			return (1);
	}
	return (0);
}
