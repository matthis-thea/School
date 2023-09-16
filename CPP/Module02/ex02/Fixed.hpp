/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:11:58 by haze              #+#    #+#             */
/*   Updated: 2023/09/13 18:34:10 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED
#include <iostream>
#include <string>
#include <cmath>

class Fixed {
    public:
        Fixed(void);
        Fixed(const Fixed & src);
        Fixed(const int convert_number);
        Fixed(const float convert_number);
        Fixed& operator=(const Fixed& src);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        bool    operator>(const Fixed &fixed) const;
        bool    operator<(const Fixed &fixed) const;
        bool    operator>=(const Fixed &fixed) const;
        bool    operator<=(const Fixed &fixed) const;
        bool    operator==(const Fixed &fixed) const;
        bool    operator!=(const Fixed &fixed) const;
        Fixed   operator+(const Fixed &fixed) const;
        Fixed   operator-(const Fixed &fixed) const;
        Fixed   operator*(const Fixed &fixed) const;
        Fixed   operator/(const Fixed &fixed) const;
        Fixed   &operator++(void);
        Fixed   operator++(int);
        Fixed   &operator--(void);
        Fixed   operator--(int);
        static Fixed& min( Fixed &src, Fixed &src_o);
        static const Fixed& min( const Fixed &src, const Fixed &src_o);
        static Fixed& max( Fixed &src, Fixed &src_o);
        static const Fixed& max( const Fixed &src, const Fixed &src_o);
    private:
        int _number_comma_int;
        static const int _number_comma_const = 8;
};
std::ostream &operator<<(std::ostream &o, Fixed const &src);
#endif
