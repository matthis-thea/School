/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PASS.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:45 by mthea             #+#    #+#             */
/*   Updated: 2024/02/08 13:48:22 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::verification_Pass(std::vector<std::string> buffer_vector, int i, int client_pos)
{
    if ((buffer_vector[i + 1].empty()))
	{
		send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_NEEDMOREPARAMS(_client_socket[client_pos]._ip_address, "PASS"));
	}
	else if (_client_socket[client_pos].boolean_connected == 1)
		send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_ALREADYREGISTERED(_client_socket[client_pos]._ip_address));
	else
	{
		_client_socket[client_pos]._Pass = buffer_vector[i + 1];  
	}
	std::cout << GRN << "Client id " << NC << RED << _client_socket[client_pos]._tab_client_Socket << NC <<  GRN << " Pass accepted" << NC << std::endl << std::endl;
}