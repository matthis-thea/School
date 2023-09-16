/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 09:04:17 by mthea             #+#    #+#             */
/*   Updated: 2023/08/30 21:40:18 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define WEAPON

#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string _type;
	public:
	Weapon(std::string new_value);
	~Weapon(void);
	std::string	getType(void);
	int				setType(std::string new_value);
};
#endif
