/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:54:37 by haze              #+#    #+#             */
/*   Updated: 2023/12/17 15:33:52 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void) argv;

	if (argc == 2)
	{
		BitcoinExchange bitcoin;
		bitcoin.Open_Csv("data.csv");
		bitcoin.Open_txt(argv[1]);
	}
	else
		std::cout << "Error: could not open file." << std::endl;
		
}