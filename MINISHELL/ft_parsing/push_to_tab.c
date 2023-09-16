/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:40:56 by tserdet           #+#    #+#             */
/*   Updated: 2023/08/20 16:20:00 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	push_lines_command(char *prompt, t_util *util)
{
	while (prompt[util->i] == ' ' || prompt[util->i] == '	')
		util->i++;
	while (prompt[util->i] != ' ' && prompt[util->i] != '	'
		&& prompt[util->i] != '\0' && prompt[util->i] != '|'
		&& prompt[util->i] != '<' && prompt[util->i] != '>')
		push_lines_command_bis(prompt, util);
	util->j = 0;
	util->k++;
	return (0);
}

int	push_args(char *prompt, t_util *util)
{
	while (prompt[util->i] != '|' && prompt[util->i] != '<'
		&& prompt[util->i] != '>' && prompt[util->i] != '\0'
		&& prompt[util->i] != ' ' && prompt[util->i] != '	')
		if (push_args_bis(prompt, util) == 1)
			return (1);
	while (prompt[util->i] == ' ' || prompt[util->i] == '	')
		util->i++;
	return (0);
}

int	push_lines_arg(char *prompt, t_util *util)
{
	while (prompt[util->i] == ' ' || prompt[util->i] == '	')
		util->i++;
	while (prompt[util->i] != '|' && prompt[util->i] != '<'
		&& prompt[util->i] != '>' && prompt[util->i] != '\0')
	{
		push_args(prompt, util);
		util->j = 0;
		util->k++;
	}
	return (0);
}

int	push_lines_pipe(char *prompt, t_util *util)
{
	while (prompt[util->i] == '<' || prompt[util->i] == '>'
		|| prompt[util->i] == '|')
	{
		util->tab[util->k][util->j] = prompt[util->i];
		util->j++;
		util->i++;
	}
	util->j = 0;
	util->k++;
	return (0);
}

int	push_to_tab(char *prompt, t_util *util)
{
	while (prompt[util->i] != '\0')
	{
		push_lines_command(prompt, util);
		push_lines_arg(prompt, util);
		push_lines_pipe(prompt, util);
	}
	return (0);
}
