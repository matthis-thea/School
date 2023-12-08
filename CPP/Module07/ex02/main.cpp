/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:13:14 by haze              #+#    #+#             */
/*   Updated: 2023/12/08 13:25:49 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
	Array<int> arrInt(5);
	Array<char> arrChar(5);
	Array<std::string> arrString(3);

	arrInt[0] = 10;
	arrInt[1] = 11;
	arrInt[2] = 12;
	arrInt[3] = 13;
	arrInt[4] = 14;

	arrChar[0] = 'a';
	arrChar[1] = 'b';
	arrChar[2] = 'c';
	arrChar[3] = 'd';
	arrChar[4] = 'e';

	arrString[0] = "hello";
	arrString[1] = "world";
	arrString[2] = ":D";

	std::cout << "INT ARRAY:" << std::endl;
	std::cout << "size: " << arrInt.size() << std::endl;
	for (std::size_t i = 0; i < arrInt.size(); ++i) {
		std::cout << arrInt[i] << std::endl;
	}

	std::cout << "CHAR ARRAY:" << std::endl;
	std::cout << "size: " << arrChar.size() << std::endl;
	for (std::size_t i = 0; i < arrChar.size(); ++i) {
		std::cout << arrChar[i] << std::endl;
	}

	std::cout << "STRING ARRAY:" << std::endl;
	std::cout << "size: " << arrString.size() << std::endl;
	for (std::size_t i = 0; i < arrString.size(); ++i) {
		std::cout << arrString[i] << std::endl;
	}

	std::cout << "\n========== EXCEPTIONS ==========\n" << std::endl;

	try {
		std::cout << arrString[1] << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << arrString[-1] << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << arrString[5] << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "========== COPY CONSTRUCTOR (DEEP) ==========" << std::endl;

	Array<std::string> copy(arrString);

	std::cout << "STRING ARRAY:" << std::endl;
	std::cout << "size: " << arrString.size() << std::endl;
	for (std::size_t i = 0; i < arrString.size(); ++i) {
		std::cout << arrString[i] << std::endl;
	}
	std::cout << "COPY ARRAY:" << std::endl;
	std::cout << "size: " << copy.size() << std::endl;
	for (std::size_t i = 0; i < copy.size(); ++i) {
		std::cout << copy[i] << std::endl;
	}
	return 0;
}