/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:08:50 by mthea             #+#    #+#             */
/*   Updated: 2023/08/29 11:08:10 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	std::string megaphone;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int i = 1;
		int j = 0;
		char c = 0;
		while (argv[i])
		{
			while (argv[i][j])
			{
				c = toupper(argv[i][j]);
				std::cout << c ;
				j++;
			}
			i++;
			j = 0;
			std::cout << " ";
		}
	}
	std::cout << std::endl ;
	return (0);
}
