/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:56:49 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 12:17:00 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG
#define WRONG
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

class WrongCat : public WrongAnimal
{
    protected:
        std::string _type;
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