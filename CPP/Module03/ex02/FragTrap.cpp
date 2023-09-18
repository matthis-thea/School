/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:39:52 by haze              #+#    #+#             */
/*   Updated: 2023/09/18 02:59:12 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << DDD << "FragTrap constructor " << _name << " was created" << NC << std::endl;
}

FragTrap::FragTrap(void) {
	this->_name = "Soldat Ryan";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << DDD << "FragTrap constructor " << _name << " was created" << NC << std::endl;
}

FragTrap::FragTrap(const FragTrap &clap) : ClapTrap(clap){
	std::cout << DDD << "FragTrap Copy constructor called" << NC << std::endl;
    *this = clap;
}

FragTrap& FragTrap::operator=(const FragTrap &clap)
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

FragTrap::~FragTrap(void) {
	std::cout << DDD << "FragTrap Deconstructor called" << NC << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << DDD << "ScavTrap " << this->_name << " is a positive high fives !" << NC << std::endl;
}