/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOPIC.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:47:30 by thib              #+#    #+#             */
/*   Updated: 2024/02/20 10:44:37 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::topicShow(std::string channelName, int idClient, int i)
{
    if(_findChannel(channelName) == true)
    {
        if(ChannelMap[channelName]->isClientInChannel(idClient) == false)
            send_msg(idClient, ERR_NOTONCHANNEL(_client_socket[i]._Nick, channelName));
        else
        {
            if (ChannelMap[channelName]->getTopic().empty() == 0)
                send_msg(idClient, RPL_TOPIC(_client_socket[i]._Nick, channelName, ChannelMap[channelName]->getTopic()));
            else
                send_msg(idClient, RPL_NOTOPIC(_client_socket[i]._Nick, channelName));
        }  
    }
    else
        send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
}

void Server::topicSet(std::string channelName, std::string value, int idClient, int i)
{
    if(_findChannel(channelName) == true)
    {
        if(ChannelMap[channelName]->isClientInChannel(idClient) == false)
            send_msg(idClient, ERR_NOTONCHANNEL(_client_socket[i]._Nick, channelName));
        else
        { 
            if (ChannelMap[channelName]->isIdOperator(idClient) == 1 && ChannelMap[channelName]->getTopicRestriction() == 0)
            {
                ChannelMap[channelName]->setTopic(value);
                send_msgs(channelName, TOPIC(_client_socket[i]._Nick, channelName, value), idClient, 1);
            }
            else
                send_msg(idClient, ERR_CHANOPRIVSNEEDED(_client_socket[i]._Nick, channelName));
        }  
    }
    else
        send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
}