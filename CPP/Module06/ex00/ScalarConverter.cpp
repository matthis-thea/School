/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:46:15 by haze              #+#    #+#             */
/*   Updated: 2023/11/24 16:28:03 by haze             ###   ########.fr       */
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

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &src)
{
	(void) src;
	std::cout << "Surchage ScalarConverter constructor was created" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter deconstructor was created" << std::endl;
}

static int if_char(const std::string &literal)
{
	std::string toChar = "";
	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) 
	{
		toChar = literal[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return (1);
	}
	return (0);
}

static void if_other(const std::string &literal)
{
	std::string specialTypes[6] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };
	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

	toInt = std::atoi(literal.c_str());

	if (literal[literal.length() - 1] == 'f')
	{
		toFloat = std::atof(literal.c_str());
		toDouble = static_cast<double>(toFloat);
	} 
	else 
	{
		toDouble = std::atof(literal.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; ++i) {
		if (literal == specialTypes[i]) 
		{
			toChar = "impossible";
			break;
		}
	}
	if (toChar == "" && std::isprint(toInt))
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	} 
	else if (toChar == "") 
	{
		toChar = "Non displayable";
	}

	std::cout << "char: " << toChar << std::endl;
	if (toChar == "impossible") 
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << toInt << std::endl;
	if (toChar == "impossible" && toFloat == 0)
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	} 
	else 
	{
		if (toChar != "impossible" && toFloat - static_cast<int>(toFloat) == 0) 
		{
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		} 
		else 
		{
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}

void ScalarConverter::convert(const std::string& literal)
{

	if (if_char(literal) == 1)
		return ;
	if_other(literal);
}