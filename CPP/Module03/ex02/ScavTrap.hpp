/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:56:33 by haze              #+#    #+#             */
/*   Updated: 2023/09/18 03:02:22 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP
#define SCAV_TRAP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(void);
		ScavTrap(const ScavTrap &clap);
		ScavTrap &operator=(const ScavTrap &clap);
		~ScavTrap();
		void guardGate();
		void attack(const std::string &target);
};

#endif