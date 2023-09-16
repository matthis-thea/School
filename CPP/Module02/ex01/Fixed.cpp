/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 09:05:47 by haze              #+#    #+#             */
/*   Updated: 2023/09/13 18:43:21 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    _number_comma_int = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int convert_number)
{
    _number_comma_int = convert_number << _number_comma_const;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float convert_number)
{
    _number_comma_int = roundf(convert_number * (1 << _number_comma_const));
    std::cout << "Float constructor called" << std::endl;
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
    return (this->_number_comma_int);
}

void       Fixed::setRawBits(int const raw) {
    this->_number_comma_int = raw;
}

float   Fixed::toFloat( void ) const 
{
    return static_cast<float>(this->getRawBits() ) / ( 1 << _number_comma_const);
}


int     Fixed::toInt(void) const
{
    return (this->_number_comma_int >> _number_comma_const);
}

std::ostream & operator<<( std::ostream & o, Fixed const & src) {
    o << src.toFloat();
    return (o);
}
