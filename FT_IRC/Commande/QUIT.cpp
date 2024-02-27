/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   QUIT.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:41:16 by tserdet           #+#    #+#             */
/*   Updated: 2024/02/20 12:41:19 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::quit(int idClient, int i, std::string reason)
{
    std::cout << "-------------------QUIT-------------------" << "\n";
    // Utilisation d'un itérateur sur une map de pointeurs vers Channel
    std::map<std::string, Channel*>::iterator it = ChannelMap.begin();
    std::string toErase;
    _client_socket[i].invitations.clear();
    while (it != ChannelMap.end()) //pour chaque channel
    {   
        if (ChannelMap[it->first]->isClientInChannel(idClient))
        {
            ChannelMap[it->first]->removeClient(idClient, ChannelMap[it->first]->_clientInChannel[idClient]);//supprimer le client
            if(ChannelMap[it->first]->isIdOperator(idClient) == 1)//supprimer de la liste des operateurs
                ChannelMap[it->first]->removeOperator(ChannelMap[it->first]->_clientInChannel[idClient], idClient);
            if (ChannelMap[it->first]->getClientNumber() == 0)//supprimer le channel si le user etait le dernier client
            {
                toErase = it->first;
                ++it;
                delete ChannelMap[toErase]; // Suppression du pointeur vers Channel
                ChannelMap.erase(toErase);
                std::cout << REDB << "Channel " << toErase << " deleted" << NC << "\n";
                _listChannels();
            }
            else
                send_msgs(it->first, QUIT(_client_socket[i]._Nick, reason), idClient, 0);//prevenir les autres utilisateurs
        }
        else
            ++it;
    }
}