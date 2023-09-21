/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:37:43 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 13:22:29 by haze             ###   ########.fr       */
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

class AAnimal
{
    protected:
        std::string _type;
	public:
		AAnimal(std::string name);
		AAnimal(void);
		AAnimal(const AAnimal &clap);
		AAnimal &operator=(const AAnimal &clap);
		virtual ~AAnimal();
		std::string     getType(void) const;
		virtual void makeSound() const = 0;
};

#endif