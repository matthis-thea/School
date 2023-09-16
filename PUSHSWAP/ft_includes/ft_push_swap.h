/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:27:40 by mthea             #+#    #+#             */
/*   Updated: 2023/03/07 16:32:59 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_swap
{
	int	max;
	int	*stack_a;
	int	*stack_temp;
	int	*stack_b;
	int	temp;
	int	i;
	int	j;
}				t_swap;
int				ft_realloc_stack_pb(t_swap *s, int max);
void			ft_realloc_stack_pa_bis(t_swap *s, int *j, int *i, int *max);
int				ft_realloc_stack_pa(t_swap *s, int max);
int				ft_realloc_stack_b(t_swap *s);
int				ft_allocation_all_tab(t_swap *s);
t_swap			*ft_allocation_tab(t_swap *s, int taille, char **argv);
t_swap			*ft_allocation_tab_bis(t_swap *s, int taille, char **argv);
int				ft_sort_tab_a(t_swap *s);
void			ft_sort_tab_temp(t_swap *s);
void			ft_convert_stack_a(t_swap *s);
void			ft_sorted_bis(int max_bits, int pos, t_swap *s);
void			ft_big_sorted(t_swap *s);
int				ft_argc_equal_two(t_swap *s, char **argv);
int				ft_argc_more_two(t_swap *s, char **argv, int argc);
void			ft_ra(t_swap *s, int max);
void			ft_pb(t_swap *s, int max);
void			ft_pa(t_swap *s, int max);
void			ft_sa(t_swap *s);
void			ft_rra(t_swap *s, int max);
void			ft_length_three(t_swap *s, int taille);
void			ft_length_fivebis(t_swap *s, int taille);
void			ft_length_five(t_swap *s, int taille);
void			ft_length_four(t_swap *s, int taille);
void			ft_final_sorted(t_swap *s, int taille);
void			ft_length_fivebis_two(t_swap *s, int taille, int posi);
char			**ft_free_malloc(char **tab, int pos);
int				ft_alloc_nb_col(const char *s, char c);
char			**ft_alloc_totale(const char *s, char c, char **tab);
char			**ft_placement_mots(const char *s, char c, char **tab);
char			**ft_split(char const *s, char c);
int				ft_verif_if_is_number_bis(char **tab);
int				ft_verif_if_is_int_bis(char **tab);
int				ft_verif_if_is_doublon_bis(char **tab, int taille);
int				ft_verif_if_is_totale_bis(char **tab);
int				ft_verif_if_is_number(char **tab);
long long int	ft_atoi(char *thestring);
int				ft_verif_if_is_int(char **tab);
int				ft_verif_if_is_doublon(char **tab, int taille);
int				ft_verif_if_is_totale(char **tab, int taille);
int				ft_strlen_if_two(char **argv);
void			ft_alloc_for_two(char **argv, int verif, t_swap *s);
void			ft_free_all(t_swap *s);
int				ft_pos(t_swap *s, int taille);
int				ft_sort_tab_a_length_five(t_swap *s);
#endif