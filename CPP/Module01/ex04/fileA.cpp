/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:38:50 by mthea             #+#    #+#             */
/*   Updated: 2023/09/01 18:56:32 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileA.hpp"

File::File(void)
{
	std::cout << "Constructor called" << std::endl;
}

File::~File(void)
{
	std::cout << "Deconstructor called" << std::endl;
}

int File::file_replace(std::string file, std::string f_arg, std::string s_arg)
{
	std::string duplicate;
	std::ifstream file_a(file);
	std::ofstream file_b(file + std::string(".replace"));

	if (f_arg == s_arg)
	{
		std::cout << "Same Words" << std::endl;
		return (0);
	}
	if (f_arg.empty())
	{
		std::cout << "The words to remplace is NULL" << std::endl;
		return (0);
	}
	if (file_a.is_open() && file_b.is_open())
	{
		file_a.seekg(0, file_a.beg);
		getline(file_a, duplicate, '\0');
		std::cout << "value of the file before change :" << duplicate << std::endl;
    	size_t  index = duplicate.find(f_arg);
		while(index != std::string::npos)
		{
			duplicate.erase(index, f_arg.size());
			duplicate.insert(index, s_arg);
			index = duplicate.find(f_arg);
		}
		file_b << duplicate;
		std::cout << "value of the file after change :" << duplicate << std::endl;

	}
	else
	{
		std::cout << "File not open or error with replace file" << std::endl;
		file_a.close();
		file_b.close();
	}
	return (1);
}