/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:41:11 by haze              #+#    #+#             */
/*   Updated: 2023/11/22 16:50:50 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
	public:
		public:
			ScalarConverter();
			ScalarConverter(const ScalarConverter &src);
			ScalarConverter& operator=(const ScalarConverter &src);
			~ScalarConverter();
			static void convert(const std::string &literal);
};

#endif