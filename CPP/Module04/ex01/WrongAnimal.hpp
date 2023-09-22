/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:25:11 by mthea             #+#    #+#             */
/*   Updated: 2023/09/22 10:26:09 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL
#define WRONGANIMAL
#include <iostream>
#include <string>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class WrongAnimal
{
    protected:
        std::string _type;
	public:
		WrongAnimal(std::string name);
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &clap);
		WrongAnimal &operator=(const WrongAnimal &clap);
		virtual ~WrongAnimal();
		std::string     getType(void) const;
		void makeSound() const ;
};

#endif
