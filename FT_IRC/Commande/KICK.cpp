/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KICK.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:21:02 by tserdet           #+#    #+#             */
/*   Updated: 2024/02/20 13:48:37 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::kick(std::string channelName, std::string reason,  int idClient, int idKicked, int i)
{
    if (_findChannel(channelName) == true && ChannelMap[channelName]->isIdOperator(idClient) == 1)
    {
        std::cout << "-------------------KICK-------------------" << "\n";

        if(_findChannel(channelName) == true && ChannelMap[channelName]->isClientInChannel(idClient) == false)
        {
            send_msg(idClient, ERR_NOTONCHANNEL(_client_socket[i]._Nick, channelName));
        }
        else if(_findChannel(channelName) == true && ChannelMap[channelName]->isClientInChannel(idKicked) == false)
        {
            send_msg(idClient, ERR_USERNOTINCHANNEL(_client_socket[i]._Nick, ChannelMap[channelName]->_clientInChannel[idClient], channelName));
        }
        else if(_findChannel(channelName) == true)
        {
            send_msgs(channelName, KICK(_client_socket[i]._Nick, channelName, ChannelMap[channelName]->_clientInChannel[idKicked], reason), idClient, 1);
            ChannelMap[channelName]->removeClient(idKicked, ChannelMap[channelName]->_clientInChannel[idKicked]);
            ChannelMap[channelName]->listClients();
            if(ChannelMap[channelName]->getClientNumber() == 0)
            {
                delete ChannelMap[channelName];
                ChannelMap.erase(channelName);
                std::cout << REDB << "Channel " << channelName << " deleted" << NC << "\n";
                _listChannels();
            }
        }
        else if(_findChannel(channelName) == false)
            send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
    }
    else
        send_msg(idClient, ERR_CHANOPRIVSNEEDED(_client_socket[i]._Nick, channelName));
}