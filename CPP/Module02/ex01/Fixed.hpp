/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:16:29 by haze              #+#    #+#             */
/*   Updated: 2023/09/13 18:42:35 by haze             ###   ########.fr       */
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
    private:
        int _number_comma_int;
        static const int _number_comma_const = 8;
};
std::ostream &operator<<(std::ostream &o, Fixed const &src);
#endif
