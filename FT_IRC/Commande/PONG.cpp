/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PONG.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:51:46 by mthea             #+#    #+#             */
/*   Updated: 2024/02/08 15:03:53 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::Pong(std::vector<std::string> buffer_vector, int i, int client_pos)
{
    if (buffer_vector[i + 1].compare("Irc_Serv_Thib_Mat") != 0)
        send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_NOSUCHSERVER(_client_socket[client_pos]._Nick, buffer_vector[i + 1]));
    else
    {
        send_msg(_client_socket[client_pos]._tab_client_Socket, PONG(buffer_vector[i + 1]));
        std::cout << CYN << "Serveur Irc_Serv_Thib_Mat sent message PONG " << NC << std::endl << std::endl;
    }
        
}