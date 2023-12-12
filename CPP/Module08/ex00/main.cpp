/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:24:54 by haze              #+#    #+#             */
/*   Updated: 2023/12/12 10:44:33 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) 
{
	std::vector<int> tab;
	std::vector<int>::iterator it;

	for (int i = 1; i < 10; i++)
	{
		tab.push_back(i);
	}
	std::cout << "Vector:" << std::endl;
	for (std::vector<int>::iterator i = tab.begin(); i != tab.end(); i++) 
	{
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;

	it = easyfind(tab, 5);
	if (it == tab.end()) 
		std::cout << "doesn't exist" << std::endl;
	else 
		std::cout << *it << " was found "<< std::endl;

	it = easyfind(tab, 8);
	if (it == tab.end()) 
		std::cout << "doesn't exist" << std::endl;
	else 
		std::cout << *it << " was found "<< std::endl;

	it = easyfind(tab, 11);
	if (it == tab.end()) 
		std::cout << "doesn't exist" << std::endl;
	else 
		std::cout << *it << " was found "<< std::endl;

	it = easyfind(tab, -6);
	if (it == tab.end()) 
		std::cout << "doesn't exist" << std::endl;
	else 
		std::cout << *it << " was found "<< std::endl;

	return (0);
}