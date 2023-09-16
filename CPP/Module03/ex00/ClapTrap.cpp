/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:27:22 by haze              #+#    #+#             */
/*   Updated: 2023/09/15 17:21:38 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << CYN << "ClapTrap constructor " << _name << " was created" << NC << std::endl;
}

ClapTrap::ClapTrap(void) {
	this->_name = "Soldat Ryan";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << CYN << "ClapTrap constructor " << _name << " was created" << NC << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clap) {
	std::cout << CYN << "Copy constructor called" << NC << std::endl;
    *this = clap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap)
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

ClapTrap::~ClapTrap(void) {
	std::cout << CYN << "ClapTrap deconstructor called" << NC << std::endl;
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << GRN << "ClapTrap " << _name << " attacks " << target <<" , causing " << _attack_damage << " points of damage!" << NC << std::endl;
		_energy_points--;
	}
	else
		std::cout << RED << "ClapTrap " << _name << " has no more energy" << NC << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= this->_hit_points)
	{
		std::cout << GRN << "ClapTrap " << _name << " take " << amount << " damage !" << NC << std::endl;
		this->_hit_points -= amount;
	}
	else
		std::cout << RED << "ClapTrap " << _name << " have " << this->_hit_points << " health, amount is too high !" << NC << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << GRN << "ClapTrap " << _name << " take " << amount << " hit points back !" << NC << std::endl;
		_energy_points--;
		this->_hit_points += amount;
	}
	else
		std::cout << RED << "ClapTrap " << _name << " has no more energy or health !" << NC << std::endl;
}