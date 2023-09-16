/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:07:21 by mthea             #+#    #+#             */
/*   Updated: 2023/08/30 21:17:41 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB
#define HUMANB

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	_name;
		Weapon* _weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);
};

#endif
