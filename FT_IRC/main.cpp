/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:24:38 by mthea             #+#    #+#             */
/*   Updated: 2024/01/27 15:19:12 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Server/server.hpp"

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		Server server(argv[1], argv[2]);
		server.start_server();
	}
	else
		std::cout << "Arg Error : ./executable Port Password\n" << std::endl;
	return (0);
}
