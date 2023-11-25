/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Function.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:49:56 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 11:57:40 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <stdint.h>

Base *generate(void)
{
	std::srand(time(NULL));

	int n = rand() % 3;
	if (n == 0)
	{
		std::cout << "New A class" << std::endl;
		return new A;
	}
	else if (n == 1)
	{
		std::cout << "New B class" << std::endl;
		return new B;
	}
	else if (n == 2)
	{
		std::cout << "New C class" << std::endl;
		return new C;
	}
	return NULL;
}

void identify(Base* p)
{
	A& identify = dynamic_cast<A&>(p);
	std::cout << "Class A in identify(Base *p)" << std::endl;
}