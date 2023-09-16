/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:21:28 by mthea             #+#    #+#             */
/*   Updated: 2023/08/30 08:35:36 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int			nb_zombie = 0;
	std::string name;
	std::cout << CYN << "Pass the name for your zombie ?" << NC << std::endl;
	std::getline(std::cin, name);
	std::cout << CYN << "How much zombie do you want ?" << NC << std::endl;
	std::cin >> nb_zombie;
	if (nb_zombie <= 0 || isdigit(nb_zombie)) {
		std::cout << RED << "Please enter a positive number" << NC << std::endl;
		return (0);
	}
	Zombie* zombie = zombieHorde(nb_zombie, name);
	zombie->boucle_announce(nb_zombie, zombie);
	delete[] zombie;
	return (0);
}
