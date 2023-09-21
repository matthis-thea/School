/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:47:13 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 12:49:12 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain constructor was created" << std::endl;
}

Brain::Brain(const Brain &clap) {
	std::cout << "Brain Copy constructor called" << std::endl;
    *this = clap;
}

Brain& Brain::operator=(const Brain &clap)
{
	if (this != &clap)
	{
		for (int i = 0; i < 100; i++) {
            this->_ideas[i] = clap._ideas[i];
        }
	}
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Brain deconstructor called" << std::endl;
}