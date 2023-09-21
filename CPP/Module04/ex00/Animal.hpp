/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:37:43 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 02:47:47 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL
#define ANIMAL
#include <iostream>
#include <string>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class Animal
{
    protected:
        std::string _type;
	public:
		Animal(std::string name);
		Animal(void);
		Animal(const Animal &clap);
		Animal &operator=(const Animal &clap);
		~Animal();
		std::string     getType( void ) const;
		void make 
};

#endif