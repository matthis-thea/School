/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:53:53 by tserdet           #+#    #+#             */
/*   Updated: 2023/08/20 16:20:14 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	check_only_spaces(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i] != '\0')
	{
		if (prompt[i] != ' ' && prompt[i] != '	')
			return (1);
		i++;
	}
	return (0);
}

int	check_begin_pipe(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i] == ' ' || prompt[i] == '	')
		i++;
	if (prompt[i] == '<' || prompt[i] == '>' || prompt[i] == '|')
		return (1);
	else
		return (0);
}

int	check_close_quote_bis(char *prompt, t_util *util)
{
	util->i++;
	util->compt1++;
	while (prompt[util->i] != 34 && prompt[util->i] != '\0')
		util->i++;
	if (prompt[util->i] == 34)
	{
		util->compt1++;
		util->i++;
	}
	return (0);
}

void	check_pipes_bis(char *prompt, t_util *util)
{
	while (prompt[util->i] == 34 || prompt[util->i] == 39)
	{
		if (prompt[util->i] == 34)
		{
			util->i++;
			while (prompt[util->i] != 34)
				util->i++;
			util->i++;
		}
		if (prompt[util->i] == 39)
		{
			util->i++;
			while (prompt[util->i] != 39)
				util->i++;
			util->i++;
		}
	}
}

void	check_arround_pipes_bis(char *prompt, t_util *util)
{
	while (prompt[util->i] == 34 || prompt[util->i] == 39)
	{
		if (prompt[util->i] == 34)
		{
			util->i++;
			while (prompt[util->i] != 34)
				util->i++;
			util->i++;
		}
		if (prompt[util->i] == 39)
		{
			util->i++;
			while (prompt[util->i] != 39)
				util->i++;
			util->i++;
		}
	}
}
