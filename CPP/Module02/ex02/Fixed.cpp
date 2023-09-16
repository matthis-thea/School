/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:19:11 by haze              #+#    #+#             */
/*   Updated: 2023/09/13 18:46:21 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void){
    _number_comma_int = 0;
}

Fixed::Fixed(const int convert_number){
    _number_comma_int = convert_number << _number_comma_const;
}

Fixed::Fixed(const float convert_number){
    _number_comma_int = roundf(convert_number * (1 << _number_comma_const));
}

Fixed::Fixed(const Fixed & src) {
    *this = src;
}

Fixed::~Fixed(void) {
}

Fixed& Fixed::operator=(const Fixed &src){
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
    return static_cast<float>( this->getRawBits() ) / ( 1 << _number_comma_const );
}


int     Fixed::toInt(void) const{
    return (this->_number_comma_int >> _number_comma_const);
}

std::ostream & operator<<( std::ostream & o, Fixed const & src) {
    o << src.toFloat();
    return o;
}

bool    Fixed::operator>(const Fixed &fixed) const{
	return (this->toFloat() > fixed.toFloat());
}

bool    Fixed::operator<(const Fixed &fixed) const{
	return (this->toFloat() < fixed.toFloat());
}

bool    Fixed::operator>=(const Fixed &fixed) const{
	return (this->toFloat() >= fixed.toFloat());
}

bool    Fixed::operator<=(const Fixed &fixed) const{
	return (this->toFloat() > fixed.toFloat());
}

bool    Fixed::operator==(const Fixed &fixed) const{
	return (this->toFloat() == fixed.toFloat());
}

bool    Fixed::operator!=(const Fixed &fixed) const{
	return (this->toFloat() != fixed.toFloat());
}

Fixed   Fixed::operator+(const Fixed &fixed) const{
    return (this->toFloat() + fixed.toFloat());
}

Fixed   Fixed::operator-(const Fixed &fixed) const{
    return (this->toFloat() - fixed.toFloat());
}

Fixed    Fixed::operator*(const Fixed &fixed) const{
    return (this->toFloat() * fixed.toFloat());
}

Fixed   Fixed::operator/(const Fixed &fixed) const{
     return (this->toFloat() / fixed.toFloat());
}


Fixed&   Fixed::operator++( void ) {
    ++this->_number_comma_int;
    return (*this);
}

Fixed   Fixed::operator++( int ) {
    Fixed dest( *this );
    dest._number_comma_int = this->_number_comma_int++;
    return (dest);
}

Fixed& Fixed::operator--( void ) {
    --this->_number_comma_int;
    return (*this);
}

Fixed Fixed::operator--( int ) {
    Fixed dest( *this );
    dest._number_comma_int = this->_number_comma_int--;
    return (dest);
}

Fixed& Fixed::min( Fixed &src, Fixed &src_o) {
    if ( src.toFloat() < src_o.toFloat() )
        return (src);
    return (src_o);
}

const Fixed& Fixed::min( const Fixed &src, const Fixed &src_o) {
    if ( src.toFloat() < src_o.toFloat() )
        return (src);
    return (src_o);
}

Fixed& Fixed::max( Fixed &src, Fixed &src_o) {
    if ( src.toFloat() > src_o.toFloat() )
        return (src);
    return (src_o);
}

const Fixed& Fixed::max( const Fixed &src, const Fixed &src_o) {
    if ( src.toFloat() > src_o.toFloat() )
        return (src);
    return (src_o);
}