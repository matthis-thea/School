/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 02:39:58 by haze              #+#    #+#             */
/*   Updated: 2023/09/18 03:02:16 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP
#define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(void);
		FragTrap(const FragTrap &clap);
		FragTrap &operator=(const FragTrap &clap);
		~FragTrap();
		void    highFivesGuys(void);
};

#endif
