/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:52:27 by mthea             #+#    #+#             */
/*   Updated: 2022/11/26 11:50:22 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h> 
# include <stdarg.h>

int	ft_count_return_nb(int n);
int	ft_count_return_nb_u(unsigned int n);
int	ft_count_return_nb_long(unsigned long long n);
int	ft_printf_nb_x(unsigned int nbr, int *verification);
int	ft_printf_nb_big_x(unsigned int nbr, int *verification);
int	ft_printf_nb(int n, int *verification);
int	ft_printf_nb_u(unsigned int n, int *verification);
int	ft_print_value(va_list args, char str, int *verification);
int	ft_printf(const char *str, ...);
int	ft_printf_c(char c, int *verification);
int	ft_printf_s(char *s, int *verification);
int	ft_printf_void(unsigned long long nb, int *verification);
int	ft_count_return_nb_x(unsigned int n);
int	verification_null(int *verification);
int	verification_end(int *verification, int value);
#endif