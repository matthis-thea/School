/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:12:55 by haze              #+#    #+#             */
/*   Updated: 2023/12/04 10:23:59 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void )
{
    int a = 2;
    int b = 3;


    std::cout << "It's INT" << std::endl;
    std::cout << "          SWAP            " << std::endl;
    std::cout << "Value of A = " << a << std::endl;
    std::cout << "Value of B = " << b << std::endl;
    swap( a, b );
    std::cout << "Value of A after swap = " << a << std::endl;
    std::cout << "Value of B after swap = " << b << std::endl;

    std::cout << "          Min           " << std::endl;
    std::cout << min( a, b ) << std::endl;
     std::cout << "          Max           " << std::endl;
    std::cout << max( a, b ) << std::endl << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "It's STRING" << std::endl;
    std::cout << "          SWAP            " << std::endl;
    std::cout << "Value of C = " << c << std::endl;
    std::cout << "Value of D = " << d << std::endl;
    swap( c, d );
    std::cout << "Value of C after swap = " << c << std::endl;
    std::cout << "Value of D after swap = " << d << std::endl;

    std::cout << "          Min           " << std::endl;
    std::cout << min( c, d ) << std::endl;
     std::cout << "          Max           " << std::endl;
    std::cout << max( c, d ) << std::endl << std::endl;

    double e = 10.58;
    double f = 55.42;
    std::cout << "It's DOUBLE" << std::endl;
    std::cout << "          SWAP            " << std::endl;
    std::cout << "Value of E = " << e << std::endl;
    std::cout << "Value of F = " << f << std::endl;
    swap( e, f );
    std::cout << "Value of E after swap = " << e << std::endl;
    std::cout << "Value of F after swap = " << f << std::endl;

    std::cout << "          Min           " << std::endl;
    std::cout << min( e, f ) << std::endl;
     std::cout << "          Max           " << std::endl;
    std::cout << max( e, f ) << std::endl;

    return 0;
}
