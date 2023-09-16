/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:38:24 by haze              #+#    #+#             */
/*   Updated: 2023/08/21 12:35:58 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int	error_arg(char **argv, int argc)
{
	if (argc > 1 || argv[1])
	{
		printf("Please, just execute ./minishell without argument");
		return (0);
	}
	return (1);
}

int	main_bis(char *prompt, t_util *util, t_mini *mini)
{
	prompt = readline("\033[0;32mminishell> \033[0m");
	if (prompt == NULL)
	{
		free(util);
		return (0);
	}
	add_history(prompt);
	if (launch(prompt, util, mini) == 1)
		return (0);
	rl_on_new_line();
	reset_struct(util);
	return (1);
}

void	launch_bis(char *prompt, t_util *util, t_mini *mini)
{
	mini->s_cmd = parsing(prompt, util);
	if (mini->s_cmd[0])
	{
		mini->pipe_quote = util->pipe_inquote;
		mini->util_tab = util->intab;
		mini->if_build = ft_verif_if_pipes(mini);
		mini->taille = ft_strlen(mini->s_cmd[0]);
		ft_if_builtins_equal_one_other(mini);
	}
	if (mini->boucle == 0)
	{
		ft_free_all(mini, util, prompt);
		exit(mini->status);
	}
}

int	launch(char *prompt, t_util *util, t_mini *mini)
{
	if (verification(prompt, util) == 0)
	{
		if (parsing(prompt, util) == NULL)
		{
			ft_free_all(mini, util, prompt);
			return (1);
		}
		launch_bis(prompt, util, mini);
	}
	else if (verification(prompt, util) == 2)
	{
	}
	else
	{
		printf("\033[0;31mINVALID COMMAND!\033[0m\n");
	}
	util->pipe_inquote = 0;
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_mini	*mini;
	t_util	*util;
	char	*prompt;

	prompt = NULL;
	if (error_arg(argv, argc) == 0)
		return (0);
	util = malloc(sizeof(t_util));
	mini = malloc(sizeof(t_mini));
	if (!mini || !util || !alloc_all(util, mini, env))
		return (0);
	ft_signal();
	while (mini->boucle == 1)
	{
		if (main_bis(prompt, util, mini) == 0)
			return (mini->status);
	}
	ft_free_all(mini, util, prompt);
	return (mini->status);
}
