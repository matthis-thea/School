/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:34:02 by thib              #+#    #+#             */
/*   Updated: 2023/08/20 16:19:50 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	nmbr_args_bis(char *prompt, t_util *util)
{
	if (prompt[util->i] == 39)
	{
		util->i++;
		while (prompt[util->i] != 39)
			util->i++;
		util->i++;
	}
	else if (prompt[util->i] == 34)
	{
		util->i++;
		if_dollars_inquote(prompt, util);
		util->i++;
	}
	else
		if_dollars(prompt, util);
}

void	nmbr_args(char *prompt, t_util *util)
{
	while (prompt[util->i] != '\0' && prompt[util->i] != '|'
		&& prompt[util->i] != '<' && prompt[util->i] != '>')
	{
		while (prompt[util->i] != ' ' && prompt[util->i] != '	'
			&& prompt[util->i] != '\0' && prompt[util->i] != '|'
			&& prompt[util->i] != '<' && prompt[util->i] != '>')
			nmbr_args_bis(prompt, util);
		util->j++;
		while (prompt[util->i] == ' ' || prompt[util->i] == '	')
			util->i++;
	}
}

int	nmbr_column(char *prompt, t_util *util)
{
	while (prompt[util->i] != '\0')
	{
		while (prompt[util->i] == ' ' || prompt[util->i] == '	'
			|| prompt[util->i] == '<' || prompt[util->i] == '>'
			|| prompt[util->i] == '|')
			util->i++;
		if (prompt[util->i] != '\0' && prompt[util->i] != '<'
			&& prompt[util->i] != '>' && prompt[util->i] != '|')
			nmbr_args(prompt, util);
		while (prompt[util->i] != '\0' && prompt[util->i] != '<'
			&& prompt[util->i] != '>' && prompt[util->i] != '|')
			util->i++;
		util->j++;
	}
	return (util->j);
}

char	**parsing(char *prompt, t_util *util)
{
	int		size;

	reset_struct(util);
	size = nmbr_column(prompt, util);
	util->tab = malloc(sizeof(char *) * size + 1);
	if (!util->tab)
		return (NULL);
	util->intab = malloc(sizeof(int *) * size + 1);
	if (!util->intab)
		return (NULL);
	util->tab[size] = NULL;
	util->intab[size] = 0;
	util->list_size = size;
	reset_struct(util);
	if (alloc_nmbr_lines(prompt, util) == 1)
		return (NULL);
	reset_struct(util);
	push_to_tab(prompt, util);
	reset_struct(util);
	return (util->tab);
}
