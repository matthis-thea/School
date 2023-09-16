/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:20:55 by haze              #+#    #+#             */
/*   Updated: 2023/09/15 17:17:51 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP
#define CLAPTRAP
#include <iostream>
#include <string>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class ClapTrap
{
	protected:
		std::string _name;
		unsigned int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap(std::string name);
		ClapTrap(void);
		ClapTrap(const ClapTrap &clap);
		ClapTrap &operator=(const ClapTrap &clap);
		~ClapTrap();
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif