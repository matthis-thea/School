/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:51:46 by haze              #+#    #+#             */
/*   Updated: 2023/08/29 11:40:41 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	std::string	zombie_heap;
	std::string	zombie_stack;
	Zombie* zombie_s;
	std::cout << "Give the name of the zombie on the stack" << std::endl;
	std::getline(std::cin, zombie_stack);
	randomChump(zombie_stack);
	std::cout << std::endl;

	std::cout << "Give the name of the zombie on the heap" << std::endl;
	std::getline(std::cin, zombie_heap);
	zombie_s = newZombie(zombie_heap);
	zombie_s->announce();
	delete zombie_s;

	return (0);
}
