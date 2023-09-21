/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 02:45:31 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 02:46:15 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT
#define CAT
#include <iostream>
#include <string>
#include "Animal"
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class Cat : public Animal
{
    protected:
        std::string _type;
	public:
		Cat(std::string name);
		Cat(void);
		Cat(const Cat &clap);
		Cat &operator=(const Cat &clap);
		~Cat();
};

#endif