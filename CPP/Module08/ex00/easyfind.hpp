/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:19:32 by haze              #+#    #+#             */
/*   Updated: 2023/12/12 10:31:07 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND
#define EASYFIND

#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
typename T::iterator easyfind(T &container, int find)
{
	typename T::iterator iterat = std::find(container.begin(), container.end(), find);
	return (iterat);
}

#endif