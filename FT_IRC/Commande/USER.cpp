/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   USER.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:49:18 by mthea             #+#    #+#             */
/*   Updated: 2024/02/12 22:04:16 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::verification_User(std::vector<std::string> buffer_vector, int i, int client_pos)
{
	if (buffer_vector[i + 1].empty() || buffer_vector[i + 2].empty())
		send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_NEEDMOREPARAMS(_client_socket[client_pos]._ip_address, "USER"));
	else if ((buffer_vector[i + 1].length() > USERLEN || buffer_vector[i + 2].length() > USERLEN) && _client_socket[client_pos].boolean_connected == 0)
	{
		if (buffer_vector[i + 1].length() > 15)
		{
			buffer_vector[i + 1].erase(buffer_vector[i + 1].begin(), buffer_vector[i + 1].end() - 15);
			_client_socket[client_pos]._User = buffer_vector[i + 1];
		}
		if (buffer_vector[i + 2].length() > 15)
		{
			buffer_vector[i + 2].erase(buffer_vector[i + 2].begin(), buffer_vector[i + 2].end() - 15);
			_client_socket[client_pos]._User = buffer_vector[i + 2];
		}

	}
	else if (_client_socket[client_pos].boolean_connected == 1)
		send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_ALREADYREGISTERED(_client_socket[client_pos]._ip_address));
	else
	{
		_client_socket[client_pos]._User = buffer_vector[i + 1];
		_client_socket[client_pos]._Realname = buffer_vector[i + 2];
		std::cout << GRN << "Client id " << NC << RED << _client_socket[client_pos]._tab_client_Socket << NC <<  GRN << " User accepted" << NC << std::endl << std::endl;
	}
}