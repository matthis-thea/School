/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:33:02 by mthea             #+#    #+#             */
/*   Updated: 2023/09/03 13:32:27 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	std::string level;

	std::cout << CYN << "Choose betwenn DEBUG or INFO or WARNING or ERROR" << NC << std::endl;
	std::getline(std::cin, level);
	harl.complain(level);
}