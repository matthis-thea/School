/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 08:14:10 by mthea             #+#    #+#             */
/*   Updated: 2023/08/30 09:04:55 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

int main(void)
{
	std::string stringNM("HI THIS IS BRAIN");
	std::string*	stringPTR = &stringNM;
	std::string& 	stringREF = stringNM;

	std::cout << CYN << "Value of the sring in memory " << &stringNM << std::endl;
	std::cout << "The adress of string stocked in string PTR " << stringPTR << std::endl;
	std::cout << "The adress of string stocked in string REF " << &stringREF << std::endl << std::endl;

	std::cout << "Value of the sring " << stringNM << std::endl;
	std::cout << "Value of value pointed by stringPTR " << *stringPTR << std::endl;
	std::cout << "Value of value pointed by stringREF " << stringREF << NC << std::endl;

	return (0);
}
