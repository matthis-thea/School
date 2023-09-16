/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:16:29 by haze              #+#    #+#             */
/*   Updated: 2023/09/06 12:26:14 by mthea            ###   ########.fr       */
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
        Fixed& operator=(const Fixed& src);
        ~Fixed(void);
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int _number_comma_int;
        static const int _number_comma_const = 8;
};

#endif
