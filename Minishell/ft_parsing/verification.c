/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:43:59 by tserdet           #+#    #+#             */
/*   Updated: 2023/08/20 16:20:19 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	check_pipes(char *prompt, t_util *util)
{
	while (prompt[util->i] != '\0')
	{
		check_pipes_bis(prompt, util);
		if (prompt[util->i] == '|')
		{
			if (prompt[util->i + 1] == '|')
				return (1);
		}
		else if (prompt[util->i] == '<')
		{
			if (prompt[util->i + 2] == '<')
				return (1);
		}
		else if (prompt[util->i] == '>')
		{
			if (prompt[util->i + 2] == '>')
				return (1);
		}
		util->i++;
	}
	return (0);
}

int	check_arround_pipes(char *prompt, t_util *util)
{
	while (prompt[util->i] != '\0')
	{
		check_arround_pipes_bis(prompt, util);
		if (prompt[util->i] == '|' || prompt[util->i] == '<'
			|| prompt[util->i] == '>')
		{
			while (prompt[util->i] == '|' || prompt[util->i] == '<'
				|| prompt[util->i] == '>')
				util->i++;
			check_arround_pipes_bis(prompt, util);
			if (prompt[util->i] == ' ' || prompt[util->i] == '	')
				util->i++;
			if (prompt[util->i] == '|' || prompt[util->i] == '<'
				|| prompt[util->i] == '>'
				|| prompt[util->i] == '\0')
				return (1);
		}
		util->i++;
	}
	return (0);
}

int	check_only_pipes(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i] != '\0')
	{
		if (prompt[i] != ' ' && prompt[i] != '	' && prompt[i] != '|'
			&& prompt[i] != '<' && prompt[i] != '>')
			return (0);
		i++;
	}
	return (1);
}

int	check_close_quote(char *prompt, t_util *util)
{
	while (prompt[util->i] != '\0')
	{
		if (prompt[util->i] == 34)
			check_close_quote_bis(prompt, util);
		else if (prompt[util->i] == 39)
		{
			util->i++;
			util->compt2++;
			while (prompt[util->i] != 39 && prompt[util->i] != '\0')
				util->i++;
			if (prompt[util->i] == 39)
			{
				util->compt2++;
				util->i++;
			}
		}
		else
			util->i++;
	}
	if (util->compt1 % 2 != 0 || util->compt2 % 2 != 0)
		return (1);
	return (0);
}

int	verification(char *prompt, t_util *util)
{
	reset_struct(util);
	pipe_inquote(prompt, util);
	reset_struct(util);
	if (check_only_spaces(prompt) == 0)
		return (2);
	reset_struct(util);
	if (check_pipes(prompt, util) == 1)
		return (1);
	reset_struct(util);
	if (check_close_quote(prompt, util) == 1)
		return (1);
	reset_struct(util);
	if (check_arround_pipes(prompt, util) == 1)
		return (1);
	reset_struct(util);
	if (check_only_pipes(prompt) == 1)
		return (1);
	reset_struct(util);
	if (check_begin_pipe(prompt) == 1)
		return (1);
	reset_struct(util);
	return (0);
}
