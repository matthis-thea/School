/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:21:35 by haze              #+#    #+#             */
/*   Updated: 2023/09/08 20:55:56 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->_number_comma_int = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void) {
    std::cout << "Deconstructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
        this->_number_comma_int = src.getRawBits();
	return *this;
}

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_number_comma_int);
}

void       Fixed::setRawBits(int const raw) {
    this->_number_comma_int = raw;
}
