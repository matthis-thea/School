/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 12:19:11 by tserdet           #+#    #+#             */
/*   Updated: 2023/08/21 12:14:05 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	reset_struct(t_util *util)
{
	util->i = 0;
	util->j = 0;
	util->k = 0;
	util->free = 0;
	util->quote = 0;
	util->compt1 = 0;
	util->compt2 = 0;
}

void	free_end(t_util *util, char *prompt)
{
	int	i;

	i = 0;
	while (util->tab[i])
	{
		free(util->tab[i]);
		i++;
	}
	free(util->tab);
	free(util->intab);
	free(util);
	free(prompt);
}

void	pipe_inquote(char *prompt, t_util *util)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (prompt[i])
	{
		if (prompt[i] == 34 || prompt[i] == 39)
		{
			if (quote == 0)
				quote = 1;
			else if (quote == 1)
				quote = 0;
		}
		if (prompt[i] == '>' || prompt[i] == '<' || prompt[i] == '|')
		{
			if (quote == 1)
				util->pipe_inquote = 1;
		}
		i++;
	}
}
