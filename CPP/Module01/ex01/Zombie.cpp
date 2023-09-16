/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:16:00 by mthea             #+#    #+#             */
/*   Updated: 2023/09/03 13:26:37 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " died." << std::endl;
}

int Zombie::setZombie(std::string name)
{
	this->_name = name;
	return (1);
}

int				Zombie::setN(int N)
{
	this->_N = N;
	return (1);
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void			Zombie::boucle_announce(int N, Zombie zombie[])
{
	std::cout << CYN << "----------Call " << N << " zombies allocated for the test-----------"  << NC << std::endl << std::endl;
	std::cout << GRN << "This is the " << N << " zombies allocated !" << NC << std::endl;
	for (int i = 0; i < N; i++){
			zombie[i].announce();
		}
}
