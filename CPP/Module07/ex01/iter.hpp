/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:44:56 by haze              #+#    #+#             */
/*   Updated: 2023/12/08 12:18:17 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER
#define ITER

#include <cstdio>

template<typename T>
void iter(T *arr, std::size_t lenght, void (*f)(const T&))
{
	for (std::size_t i = 0; i < lenght; i++)
	{
		f(arr[i]);
	}
}
#endif 