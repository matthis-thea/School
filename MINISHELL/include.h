/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:12:08 by haze              #+#    #+#             */
/*   Updated: 2023/08/21 12:45:18 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
/*tibo_struct_and_functions*/
// int			g_pid_wait;

typedef struct s_util
{
	char	**tab;
	int		*intab;
	int		list_size;
	int		pipe_inquote;
	int		i;
	int		j;
	int		k;
	int		quote;
	int		free;
	int		compt1;
	int		compt2;
}					t_util;
char	**parsing(char *prompt, t_util *util);
int		alloc_nmbr_lines(char *prompt, t_util *util);
void	reset_struct(t_util *util);
int		push_to_tab(char *prompt, t_util *util);
int		verification(char *prompt, t_util *util);
int		check_only_spaces(char *prompt);
void	free_end(t_util *util, char *prompt);
int		alloc_nmbr_char_bis(char *prompt, t_util *util);
int		push_args_bis(char *prompt, t_util *util);
void	alloc_lines_command_bis(char *prompt, t_util *util);
void	push_lines_command_bis(char *prompt, t_util *util);
void	if_dollars(char *prompt, t_util *util);
void	if_dollars_inquote(char *prompt, t_util *util);
int		check_begin_pipe(char *prompt);
void	ft_signal(void);
int		nmbr_char_bis_dquote_bis(char *prompt, t_util *util);
int		nmbr_char_bis_dquote_ter(char *prompt, t_util *util);
int		alloc_lines_noquotes_bis(char *prompt, t_util *util);
int		alloc_lines_noquotes_ter(char *prompt, t_util *util);
int		args_bis_dquote_bis(char *prompt, t_util *util);
int		args_bis_dquote_ter(char *prompt, t_util *util);
int		push_arg_noquotes_bis(char *prompt, t_util *util);
int		push_arg_noquotes_ter(char *prompt, t_util *util);
int		check_close_quote_bis(char *prompt, t_util *util);
void	check_pipes_bis(char *prompt, t_util *util);
void	check_arround_pipes_bis(char *prompt, t_util *util);
void	pipe_inquote(char *prompt, t_util *util);
void	alloc_nmbr_char_ter(char *prompt, t_util *util);
void	push_args_ter(char *prompt, t_util *util);
void	args_bis_dquote_quater(char *prompt, t_util *util);
/*my_struct*/
typedef struct s_mini
{
	char	*aff_exec;
	char	***cmd_p;
	char	*str;
	char	*home;
	char	*dup_cd;
	char	**s_env;
	char	**s_cmd;
	char	*s_export;
	char	**s_dup_env;
	int		if_build;
	int		error;
	int		boolean;
	int		val_env;
	int		bool_echo;
	int		bool_dol_echo;
	int		taille;
	int		taille_cd;
	int		bool_main;
	int		cd_bool;
	int		error_pipes;
	int		status;
	int		status_pipes;
	int		export_i;
	int		exprt_bool;
	int		exit_num_bool;
	int		final_exit;
	int		equal_export;
	int		export_incr;
	int		*util_tab;
	int		boucle;
	int		cmd_len;
	int		stdout_red;
	int		stdint_red;
	int		count_pipes;
	int		fd[2];
	int		j;
	int		z;
	int		pid;
	int		pipe_quote;
	int			g_pid_wait;

}				t_mini;
/*-----------*/
/*ft_for_env*/
int		ft_for_env(char **env, t_mini *mini);
int		duplicate_env(char **env, t_mini *mini);
int		alloc_dupli_env(t_mini *mini);
int		ft_path_exist(t_mini *mini);
/*---------------*/
/*ft_if_or_not_builtins*/
void	status_out(pid_t pid, t_mini *mini);
int		ft_verif_if_pipes(t_mini *mini);
int		ft_verif_if_pipes_bis(t_mini *mini, int i);
int		ft_if_builtins_one(t_mini *mini);
int		ft_if_builtins_equal_one_other(t_mini *mini);
int		ft_if_equal_builtins(t_mini *mini, pid_t	pid);
int		ft_not_equal_builtins(t_mini *mini);
/*---------------*/
/*ft-split.c*/
char	**ft_free_malloc(char **tab, int pos);
int		ft_alloc_nb_col(const char *s, char c);
char	**ft_alloc_totale(const char *s, char c, char **tab);
char	**ft_placement_mots(const char *s, char c, char **tab);
char	**ft_split(char const *s, char c);
/*----------*/
/*ft_utils.c*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char const *str);
int		ft_strlen_deux(char **str);
char	*ft_strjoin(char const *s1, char const *s2);
/*------*/
/*ft_builtins_pwd.c*/
int		my_pwd(char **cmd);
/*-----------------*/
/*ft_builtins_env.c*/
int		my_env(char **str, char **cmd);
int		ft_cpm_export(char *s1, char s2);
/*-----------------*/
/*ft_builtins_export.c*/
int		my_export(t_mini *mini, char **cmd);
char	*cmd_after(t_mini *mini, char **cmd, int i);
int		ft_cpm_export(char *s1, char s2);
int		ft_cpm_export_bis(char *s1, char *s2, char s3, int taille);
char	*remplissage(t_mini *mini, char **cmd, int i, char *export);
/*-----------------*/
/*ft_builtins_three.c*/
char	*remplissage_bis(t_mini *mini, char **cmd, int i, char *export);
/*-----------------*/
/*ft_builtins_export_two.c*/
int		cmd_before(char **cmd, int i, t_mini *mini);
int		my_export_bis(t_mini *mini, char **cmd, int i);
int		my_export_bis_bis(t_mini *mini, char **cmd, int i);
int		verif_export(char **cmd, int i, t_mini *mini);
/*-----------------*/
/*ft_alloc.c*/
int		alloc_all(t_util *util, t_mini	*mini, char **env);
/*-----------------*/
/*ft_builtins_unset.c*/
int		my_unset(char **cmd, t_mini *mini, char **s_cmd);
char	**alloc_dupli_unset(char **str);
int		duplicate_unset(char **str, char **cmd);
int		verification_unset(char **str, t_mini *mini, char **s_cmd);
int		duplicate_unset_rev(char **str, char **cmd, t_mini *mini);
/*-----------------*/
/*ft_builtins_echo.c*/
int		ft_my_echo(char **cmd, t_mini *mini);
int		ft_echo_remove_flags(char **cmd);
/*-----------------*/
/*ft_builtins_cd_three.c and four*/
void	affichage_pwd(char **cmd, t_mini *mini);
void	dollards_cd_no_space(t_mini *mini, int z, char **cmd);
void	dollards_cd_space(t_mini *mini, int z, char **cmd);
void	dollards_cd(t_mini *mini, int z, char **cmd);
int		replace_pwd_normal(t_mini *mini, int i, int j, int z);
int		cd_error(t_mini *mini);
void	put_value_dup_help(t_mini *mini, int *i, int *z, char **cmd);
void	cd_intro_alloc(char **cmd, t_mini *mini, int *i);
/*----------------------*/
/*ft_builtins_cd.c and bis*/
int		my_cd(char **cmd, t_mini *mini);
int		cd_for_path(char **cmd, t_mini *mini);
int		put_value_dup(char **cmd, int i, int j, t_mini *mini);
int		replace_pwd(t_mini *mini, int i, int j, int z);
int		alloc_cd(t_mini *mini);
char	*pwd_search(t_mini *mini);
int		cd_for_path_bis(char **cmd, t_mini *mini);
int		put_value_dup_dot(t_mini *mini, char **cmd);
void	echo_dollards_no_space(t_mini *mini, char **cmd, int z, int i);
void	echo_dollards_space(t_mini *mini, char **cmd, int z, int i);
/*-----------------*/
/*ft_redirection_pipes_three.c*/
int		stdout_i_trois(char ***cmd, int *i, t_mini *mini, int j);
int		stdin_i_trois(char ***cmd, int	*i, t_mini *mini, int j);
int		stdin_append_trois(char ***cmd, int *i, t_mini *mini, int j);
int		stdin_normal(char ***cmd, int *i, int j, t_mini *mini);
int		stdin_double_normal(char ***cmd, int *i, int j, t_mini *mini);
/*-----------------*/
/*ft_redirection_pipes_two.c and four*/
int		ft_if_buil_one_pipes(char **cmd, t_mini *mini);
int		ft_exec_pipelines(char **cmd, t_mini *mini);
int		fork_stdin(int in, int out, char **cmd, t_mini *mini);
int		fork_stout(int test3, char **cmd, t_mini *mini);
int		stdin_normal_files_not(char ***cmd, int *i, int j, t_mini *mini);
int		stdin_normal_files(char ***cmd, int *i, int j, t_mini *mini);
/*--------------------------*/
/*ft_redirection_pipes.c*/
int		else_normal(char ***cmd, int *i, int *j, t_mini *mini);
int		stdout_trois(char ***cmd, int *i, t_mini *mini);
int		redirection_pipes(char **cmd[], t_mini *mini);
void	stdout_trois_bis(pid_t pid, t_mini *mini);
/*--------------------------*/
/*ft_pipelines.c*/
int		ft_if_builtins_one_pipes(char **cmd, t_mini *mini);
int		ft_exec_pipe(char **cmd, t_mini *mini);
int		count(char ***cmd);
void	pipeline_bis(char ***cmd, t_mini *mini, int fd[], int i);
void	wait_pipeline(int fd[], int i, t_mini *mini);
void	pipeline(char ***cmd, t_mini *mini);
char	***alloc_tab_pipes(char ***cmd);
char	***place_tab_pipes(char ***cmd, char **ls, t_mini *mini, int i);
/*-----------------*/
/*ft_builtins_exit.c*/
int		my_exit(char **cmd, t_mini *mini);
/*-----------------*/
/*ft_free_mini.c*/
char	**ft_free_malloc_mini(char **tab);
void	ft_free_all(t_mini *mini, t_util *util, char *prompt);
/*-----------------*/
/*ft_main.c*/
int		main_bis(char *prompt, t_util *util, t_mini *mini);
void	launch_bis(char *prompt, t_util *util, t_mini *mini);
int		launch(char *prompt, t_util *util, t_mini *mini);
/*-----------------*/
void	lecture(char **str);
void	lecture_simple(char *str);
#endif
