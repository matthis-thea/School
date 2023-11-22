/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:46:15 by haze              #+#    #+#             */
/*   Updated: 2023/11/22 16:52:24 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor was created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
	std::cout << "copy ScalarConverter constructor was created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void) src;
	std::cout << "Surchageizenynn ScalarConverter constructor was created" << std::endl;
	return *this;
}

void ScalarConverter::convert(const std::string &literal)
{

}