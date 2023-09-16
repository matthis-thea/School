/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:53:09 by mthea             #+#    #+#             */
/*   Updated: 2023/08/30 21:31:55 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA
#define HUMANA

#include <iostream>
#include <string>
#include "Weapon.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class HumanA
{
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		HumanA(std::string name, Weapon &Weapon);
		~HumanA(void);
		void	attack(void) const;
};

#endif
