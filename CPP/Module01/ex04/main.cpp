/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:38:11 by mthea             #+#    #+#             */
/*   Updated: 2023/09/03 13:23:47 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fileA.hpp"

int main(int argc, char **argv)
{
	File a_file;
	if (argc == 4)
		a_file.file_replace(argv[1], argv[2], argv[3]);
	std::cout << "Numbers of aruments incorrect !" << std::endl;
	return (0);
}
