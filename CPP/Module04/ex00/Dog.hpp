/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:41:59 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 02:44:59 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG
#define DOG
#include <iostream>
#include <string>
#include "Animal.hpp"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class Dog: public Animal
{
     protected:
        std::string _type;
	public:
		Dog(std::string name);
		Dog(void);
		Dog(const Dog &clap);
		Dog &operator=(const Dog &clap);
		~Dog();
        void make_sound(void) const;
};
#endif
