/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PART.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:11:32 by tserdet           #+#    #+#             */
/*   Updated: 2024/02/20 13:48:24 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::part(std::string channelName, std::string reason,  int idClient, int i)
{
    std::cout << "-------------------PART-------------------" << "\n";

    if(_findChannel(channelName) == true && ChannelMap[channelName]->isClientInChannel(idClient) == false)
    {
        send_msg(idClient, ERR_NOTONCHANNEL(_client_socket[i]._Nick, channelName));
    }
    else if(_findChannel(channelName) == true)
    {
        send_msgs(channelName, PART(_client_socket[i]._Nick, channelName, reason), idClient, 1);
        ChannelMap[channelName]->removeClient(idClient, _client_socket[i]._Nick);
        ChannelMap[channelName]->listClients();
        if(ChannelMap[channelName]->isIdOperator(idClient) == 1)//supprimer de la liste des operateurs
            ChannelMap[channelName]->removeOperator(ChannelMap[channelName]->_clientInChannel[idClient], idClient);
        if(ChannelMap[channelName]->getClientNumber() == 0)
        {
            delete ChannelMap[channelName];
            ChannelMap.erase(channelName);
            std::cout << REDB << "Channel " << channelName << " deleted" << NC << "\n";
            _listChannels();
        }
    }
    else
        send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
}