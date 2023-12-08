/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:12:55 by haze              #+#    #+#             */
/*   Updated: 2023/12/08 12:04:51 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>

void affichage_string(std::string const &stringg)
{
    std::cout << stringg << std::endl;
}

void affichage_int(int const &intt)
{
    std::cout << intt << std::endl;
}

void affichage_double(double const &doublee)
{
    std::cout << doublee << std::endl;
}

int main() {
	int arrInt[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::string arrString[4] = {"abc", "dfg", "hij", "klm"};
    double arrdouble[10] = {1.85, 2.456, 3.4898, 4.135, 5.86, 6.13, 7.146, 8.78, 9.25, 10.1254};

	std::cout << "INT " << std::endl;
	iter(arrInt, 10, &affichage_int);
    std::cout << std::endl;

    std::cout << "String " << std::endl;
	iter(arrString, 4, &affichage_string);
    std::cout << std::endl;

    std::cout << "double " << std::endl;
	iter(arrdouble, 10, &affichage_double);


	return 0;
}