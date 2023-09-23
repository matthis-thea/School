/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:25:07 by mthea             #+#    #+#             */
/*   Updated: 2023/09/23 17:46:50 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT
#define WRONGCAT
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(std::string name);
		WrongCat(void);
		WrongCat(const WrongCat &clap);
		WrongCat &operator=(const WrongCat &clap);
		virtual ~WrongCat();
		std::string     getType(void) const;
		void makeSound() const ;
};

#endif
