/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:16:56 by haze              #+#    #+#             */
/*   Updated: 2023/08/20 15:19:44 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	launch(char *prompt, t_util *util)
{
	if (verification(prompt, util) == 0)
	{
		if (parsing(prompt, util) == NULL)
			return (1);
	}
	else if (verification(prompt, util) == 2)
	{
	}
	else
		printf("\033[0;31mINVALID COMMAND!\033[0m\n");
	util->pipe_inquote = 0;
	return (0);
}

int	main(void)
{
	t_util		*util;
	char		*prompt;

	util = malloc(sizeof(t_util));
	ft_signal();
	while (1)
	{
		prompt = readline("\033[0;32mminishell> \033[0m");
		if (prompt == NULL)
		{
			free(util);
			return (0);
		}
		add_history(prompt);
		if (launch(prompt, util) == 1)
		{
			free_end(util, prompt);
			return (1);
		}
		rl_on_new_line();
		reset_struct(util);
	}
	free_end(util, prompt);
	return (0);
}
