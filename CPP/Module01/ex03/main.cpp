/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:58:01 by mthea             #+#    #+#             */
/*   Updated: 2023/08/30 21:38:36 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	std::cout << GRN << "Human A" << NC << std::endl;
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Human A", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	{
		std::cout << GRN << "Human B with weapon" << NC << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Human B");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::cout << GRN << "Human B without weapon" << NC << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Human B2");
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
