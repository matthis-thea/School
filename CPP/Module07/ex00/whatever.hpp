/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:06:54 by haze              #+#    #+#             */
/*   Updated: 2023/12/04 10:14:42 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

template<typename T>
void swap(T &x, T&y)
{
	T temp = x;
	x = y;
	y = temp;
}

template<typename T>
T min(T &x, T&y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

template<typename T>
T max(T &x, T&y)
{
	if (x > y)
		return (x);
	else
		return (y);
}


#endif 