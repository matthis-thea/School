/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:26:19 by haze              #+#    #+#             */
/*   Updated: 2023/09/15 17:20:43 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << CYN << "ScavTrap constructor " << _name << " was created" << NC << std::endl;
}

ScavTrap::ScavTrap(void) {
	this->_name = "Soldat Ryan";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << CYN << "ScavTrap constructor " << _name << " was created" << NC << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &clap) : ClapTrap(clap){
	std::cout << CYN << "ScavTrap Copy constructor called" << NC << std::endl;
    *this = clap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &clap)
{
	if (this != &clap)
	{
		this->_name = clap._name;
		this->_hit_points = clap._hit_points;
		this->_energy_points = clap._energy_points;
		this->_attack_damage = clap._attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << CYN << "ScavTrap Deconstructor called" << NC << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << REDB << "ScavTrap " << this->_name << " is now in Gate keeper mode" << NC << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << REDB << "ScavTrap " << _name << " attacks " << target <<" , causing " << _attack_damage << " points of damage!" << NC << std::endl;
		_energy_points--;
	}
	else
		std::cout << REDB << "ScavTrap " << _name << " has no more energy" << NC << std::endl;
}