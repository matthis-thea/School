/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:18:32 by haze              #+#    #+#             */
/*   Updated: 2023/09/22 10:29:59 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main( void )
{
    const Animal* A = new Animal();
    const Animal* D = new Dog();
    const Animal* C = new Cat();

    std::cout << "D Type: " << D->getType() << " " << std::endl;
    std::cout << "C Type: " << C->getType() << " " << std::endl;
    std::cout << "A Type: " << A->getType() << " " << std::endl;
    C->makeSound();
    D->makeSound();
    A->makeSound();

    delete  A;
    delete  D;
    delete  C;

    std::cout << std::endl << std::endl;
    const WrongAnimal *W = new WrongAnimal();
    const WrongAnimal *Z = new WrongCat();

    std::cout << "W Type: " << W->getType() << " " << std::endl;
    std::cout << "Z Type: " << Z->getType() << " " << std::endl;
    W->makeSound();
    Z->makeSound();

    delete  W;
    delete  Z;
    return 0;
}
