/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NICK.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:15 by mthea             #+#    #+#             */
/*   Updated: 2024/02/08 13:48:55 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::verification_Nick(std::vector<std::string> buffer_vector, int i, int client_pos)
{
	int d = 0;
	while (d < MAX_CLIENTS)
	{
		if (_client_socket[d]._Nick.compare(buffer_vector[i + 1]) == 0)
			_client_socket[client_pos].boolean_nick_inuse = 1;
		d++;
	}
	if (buffer_vector[i + 1].find(':') != std::string::npos || buffer_vector[i + 1].find('#') != std::string::npos || buffer_vector[i + 1].find("&#") != std::string::npos 
	|| buffer_vector[i + 1].find("#&") != std::string::npos || std::isdigit(buffer_vector[i + 1][0]))
		_client_socket[client_pos].boolean_nick_error = 1;
	if ((buffer_vector[i + 1].empty()))
		send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_NONICKNAMEGIVEN((_client_socket[client_pos]._ip_address)));
	else if (_client_socket[client_pos].boolean_nick_inuse == 1)
		send_msg(_client_socket[client_pos]._tab_client_Socket , ERR_NICKNAMEINUSE(_client_socket[client_pos]._ip_address, buffer_vector[i + 1]));
	else if (_client_socket[client_pos].boolean_nick_error == 1)
		send_msg(_client_socket[client_pos]._tab_client_Socket , ERR_ERRONEUSNICKNAME(_client_socket[client_pos]._ip_address, buffer_vector[i + 1]));
	else
	{
		if (_client_socket[client_pos].boolean_connected == 1)
		{
			d = 0;
			while (d < MAX_CLIENTS)
			{
				send_msg(_client_socket[d]._tab_client_Socket , CHANGE_NICK(_client_socket[client_pos]._Nick, buffer_vector[i + 1]));
				d++;
			}
		}
		_client_socket[client_pos]._Nick = buffer_vector[i + 1];
	}
	std::cout << GRN << "Client id " << NC << RED << _client_socket[client_pos]._tab_client_Socket << NC <<  GRN << " Nick accepted" << NC << std::endl << std::endl;
	_client_socket[client_pos].boolean_nick_error = 0;
	_client_socket[client_pos].boolean_nick_inuse = 0;
}