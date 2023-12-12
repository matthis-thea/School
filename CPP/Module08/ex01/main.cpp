/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:43:26 by haze              #+#    #+#             */
/*   Updated: 2023/12/12 12:14:16 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	std::cout << "Small Tab :" <<std::endl;
	try
	{
		Span small = Span(5);
		small.addNumber(6);
		small.addNumber(3);
		std::cout << small.shortestSpan() << std::endl;
		std::cout << small.longestSpan() << std::endl;
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Medium Tab :" <<std::endl;
	try
	{
		Span medium = Span(5);
		medium.addNumber(6);
		medium.addNumber(3);
		medium.addNumber(17);
		medium.addNumber(9);
		medium.addNumber(11);
		std::cout << medium.shortestSpan() << std::endl;
		std::cout << medium.longestSpan() << std::endl;
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Big Tab :" <<std::endl;
	try
	{
		std::vector<int> big(100000);
		for (int i = 0; i < 100000; ++i)
		{
			big[i] = i;
		}
		Span bigg(100000);
		bigg.Bigsize(big.begin(), big.end());
		std::cout << "shortest span: " << bigg.shortestSpan() << std::endl;
		std::cout << "longest span : " << bigg.longestSpan() << std::endl;
	}
	catch (std::exception& e) 
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}