/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:18:32 by haze              #+#    #+#             */
/*   Updated: 2023/09/21 13:47:55 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Wrong.hpp"

int main( void )
{
    std::cout << "--------------- Animal ---------------" << std::endl;

    const AAnimal* D = new Dog();
    const AAnimal* C = new Cat();

    std::cout << "D Type: " << D->getType() << " " << std::endl;
    std::cout << "C Type: " << C->getType() << " " << std::endl;
    C->makeSound();
    D->makeSound();

    delete  D;
    delete  C;

    return 0;
}