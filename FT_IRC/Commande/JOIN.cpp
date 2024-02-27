/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JOIN.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:55:36 by tserdet           #+#    #+#             */
/*   Updated: 2024/02/20 13:24:21 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::channelExist(std::string channelName, int idClient, int i, std::string symbol)
{
    std::cout << CYN << "Channel already exist\n" << NC;
    ChannelMap[channelName]->addClient(idClient, _client_socket[i]._Nick);
    ChannelMap[channelName]->listClients();
    //RPL------------------------------------------------------
    send_msgs(channelName, JOIN(_client_socket[i]._Nick, channelName), idClient, 1);
    if (ChannelMap[channelName]->getTopic().empty() == 0)
        send_msg(idClient, RPL_TOPIC(_client_socket[i]._Nick, channelName, ChannelMap[channelName]->getTopic()));
    else
        send_msg(idClient, RPL_NOTOPIC(_client_socket[i]._Nick, channelName));
    send_msg(idClient, RPL_NAMREPLY(_client_socket[i]._Nick, symbol, channelName, concatenateNames(channelName)));
    send_msg(idClient, RPL_ENDOFNAMES(_client_socket[i]._Nick, channelName));
}

void Server::join(std::string channelName, int idClient, int i, std::string key)
{
    std::string symbol = "=";
    std::cout << "-------------------JOIN-------------------" << "\n";
    if(_findChannel(channelName) == false)//si channel n'existe pas encore, en créer un
    {
        Channel* newChannel =  new Channel(channelName, idClient, _client_socket[i]._Nick);
        ChannelMap[channelName] =  newChannel;
        std::cout << GRNB << "Channel "<< ChannelMap[channelName]->getName() <<  " created\n" << NC;
        ChannelMap[channelName]->addClient(idClient, _client_socket[i]._Nick);
        ChannelMap[channelName]->listClients();
       _listChannels();
       //RPL-----------------------------------------------------------
       send_msg(idClient, JOIN(_client_socket[i]._Nick, channelName));
       send_msg(idClient, RPL_NAMREPLY(_client_socket[i]._Nick, symbol, channelName, concatenateNames(channelName)));
       send_msg(idClient, RPL_ENDOFNAMES(_client_socket[i]._Nick, channelName));
    }
    else//si channel existe déjà, rejoindre
    {
        if ((ChannelMap[channelName]->getKey().empty() == true && ChannelMap[channelName]->getI() == 0) || _client_socket[i + 4].isChannelPresent(channelName) == 1) //si il  n'y a pas de cle necessaire et pas besoin d'invvitation ou qu'il est invité
        {
            if (ChannelMap[channelName]->getClientNumber() < ChannelMap[channelName]->getMaxClient())
            {
                channelExist(channelName, idClient, i, symbol);
                std::vector<std::string>::iterator it = std::find(_client_socket[i+4].invitations.begin(), _client_socket[i+4].invitations.end(), channelName);
                if (it != _client_socket[i+4].invitations.end())
                {
                    // Supprimer l'élément trouvé
                    _client_socket[i+4].invitations.erase(it);
                }
            }
            else
                send_msg(idClient, ERR_CHANNELISFULL(_client_socket[i]._Nick, channelName));
        }
        else if(ChannelMap[channelName]->getKey().empty() == false && ChannelMap[channelName]->getI() == 0)//si mdp mais pas mode invit
        {
            if (ChannelMap[channelName]->getKey() == key)
            {
                if (ChannelMap[channelName]->getClientNumber() < ChannelMap[channelName]->getMaxClient())
                    channelExist(channelName, idClient, i, symbol);
                else
                    send_msg(idClient, ERR_CHANNELISFULL(_client_socket[i]._Nick, channelName));
            }
            else
                send_msg(idClient, ERR_BADCHANNELKEY(_client_socket[i]._Nick, channelName));
        }
        else if(ChannelMap[channelName]->getI() == 1 && _client_socket[i].isChannelPresent(channelName) == 0)//si pas invité mais mode invit
            send_msg(idClient, ERR_INVITEONLYCHAN(_client_socket[i]._Nick, channelName));
    }
}
