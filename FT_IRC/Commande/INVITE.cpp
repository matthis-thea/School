/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INVITE.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:01:56 by tserdet           #+#    #+#             */
/*   Updated: 2024/02/20 10:44:09 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::inviting(std::string channelName, int i, std::string invited)
{
    if (userExists(invited) == 1)
    {
        _client_socket[getTabClientSocketByNick(invited)].invitations.push_back(channelName);
        send_msg(getTabClientSocketByNick(invited), INVITE(_client_socket[i]._Nick, invited, channelName));
    }
    else
        std::cout << "USER "<< invited << " DOES NOT EXIST\n";
}

void Server::invite(std::string channelName, int idClient, int i, std::string invited)
{
    std::cout << "-------------------INVITE-------------------" << "\n";
    if(_findChannel(channelName) == true)
    {
        if(ChannelMap[channelName]->isClientInChannel(idClient) == true)
        {
            if (ChannelMap[channelName]->isIdOperator(idClient) == 0 && ChannelMap[channelName]->getI() == 1)
                send_msg(idClient, ERR_CHANOPRIVSNEEDED(_client_socket[i]._Nick, channelName));
            else
            {
                if (ChannelMap[channelName]->isClientInChannel(ChannelMap[channelName]->getIdByName(invited)) == 0)
                    inviting(channelName, i, invited);
                else
                    send_msg(idClient, (ERR_USERONCHANNEL(_client_socket[i]._Nick, invited, channelName)));
            }
        }
        else
            send_msg(idClient, ERR_NOTONCHANNEL(_client_socket[i]._Nick, channelName));
    }
    else
        send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
}
