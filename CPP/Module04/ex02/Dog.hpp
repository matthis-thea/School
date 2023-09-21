/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:41:59 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 13:24:35 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG
#define DOG
#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class Dog: public AAnimal
{
    protected:
        std::string _type;
	private:
		Brain *_brain;
	public:
		Dog(void);
		Dog(const Dog &clap);
		Dog &operator=(const Dog &clap);
		virtual ~Dog();
		std::string     getType(void) const;
        virtual void makeSound() const;
};
#endif
