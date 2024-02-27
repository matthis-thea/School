/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MODE.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:47:10 by thib              #+#    #+#             */
/*   Updated: 2024/02/20 10:44:20 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::modeL(std::string channelName,int idClient, int i, char aOd, std::string value)
{
    std::cout << "-------------------MODE L-------------------" << "\n";
    std::istringstream iss(value);
    int result;
    iss >> result;
    if (_findChannel(channelName) == true && ChannelMap[channelName]->isIdOperator(idClient) == 1)
    {
        if(aOd == '+')
        {
            ChannelMap[channelName]->setMaxClient(result);
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "+l", value), idClient, 1);
        }
        if (aOd == '-')
        {
            ChannelMap[channelName]->setMaxClient(2);
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "-l", ""), idClient, 1);
        }
    }
    else if(_findChannel(channelName) == false)
        send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
    else
        send_msg(idClient, ERR_CHANOPRIVSNEEDED(_client_socket[i]._Nick, channelName));
}

void Server::modeO(std::string channelName,int idClient, int i, char aOd, std::string value)
{
    std::cout << "-------------------MODE O-------------------" << "\n";
    std::istringstream iss(value);
    int result;
    iss >> result;
    if (_findChannel(channelName) == true && ChannelMap[channelName]->isIdOperator(idClient) == 1)
    {
        if(aOd == '+')
        {
            ChannelMap[channelName]->addOperator(value , ChannelMap[channelName]->getIdByName(value));
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "+o", value), idClient, 1);
        }
        if (aOd == '-')
        {
            ChannelMap[channelName]->removeOperator(value , ChannelMap[channelName]->getIdByName(value));
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "-o", ""), idClient, 1);
        }
    }
    else if(_findChannel(channelName) == false)
        send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
    else
        send_msg(idClient, ERR_CHANOPRIVSNEEDED(_client_socket[i]._Nick, channelName));
}

void Server::modeT(std::string channelName,int idClient, int i, char aOd)
{
    std::cout << "-------------------MODE T-------------------" << "\n";
    if (_findChannel(channelName) == true && ChannelMap[channelName]->isIdOperator(idClient) == 1)
    {
        if(aOd == '+')
        {
            ChannelMap[channelName]->setTopicRestriction(1);
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "+t", ""), idClient, 1);
        }
        if (aOd == '-')
        {
            ChannelMap[channelName]->setTopicRestriction(0);
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "-t", ""), idClient, 1);
        }
    }
    else if(_findChannel(channelName) == false)
        send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
    else
        send_msg(idClient, ERR_CHANOPRIVSNEEDED(_client_socket[i]._Nick, channelName));
}

void Server::modeK(std::string channelName,int idClient, int i, char aOd, std::string value)
{
    std::cout << "-------------------MODE K-------------------" << "\n";
    if (_findChannel(channelName) == true && ChannelMap[channelName]->isIdOperator(idClient) == 1)
    {
        if(aOd == '+')
        {
            ChannelMap[channelName]->setKey(value);
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "+k", value), idClient, 1);
        }
        else if(aOd == '-')
        {
            ChannelMap[channelName]->setKey("");
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "+k", ""), idClient, 1);
        }
    }
    else if(_findChannel(channelName) == false)
        send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
    else
        send_msg(idClient, ERR_CHANOPRIVSNEEDED(_client_socket[i]._Nick, channelName));
}

void Server::modeI(std::string channelName,int idClient, int i, char aOd)
{
    std::cout << "-------------------MODE I-------------------" << "\n";
    if (_findChannel(channelName) == true && ChannelMap[channelName]->isIdOperator(idClient) == 1)
    {
        if(aOd == '+')
        {
            ChannelMap[channelName]->setI(1);
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "+i", ""), idClient, 1);
        }
        if (aOd == '-')
        {
            ChannelMap[channelName]->setI(0);
            send_msgs(channelName, MODE(_client_socket[i]._Nick, channelName, "-i", ""), idClient, 1);
        }
    }
    else if(_findChannel(channelName) == false)
        send_msg(idClient, ERR_NOSUCHCHANNEL(_client_socket[i]._Nick, channelName));
    else
        send_msg(idClient, ERR_CHANOPRIVSNEEDED(_client_socket[i]._Nick, channelName));
}