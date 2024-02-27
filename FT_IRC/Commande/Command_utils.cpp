/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command_utils.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:25:36 by tserdet           #+#    #+#             */
/*   Updated: 2024/02/20 10:48:08 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

//COMMAND UTILS-------------------------------------------------------

bool Server::_findChannel(std::string name)
{
    // Utilisation d'un itérateur sur une map de pointeurs vers Channel
    std::map<std::string, Channel *>::const_iterator it;
    for (it = ChannelMap.begin(); it != ChannelMap.end(); ++it) {
        if (it->first == name) { // Comparaison des noms
            return true; // Si un canal avec le même nom est trouvé, retourne true
        }
    }
    return false; // Si aucun canal correspondant n'est trouvé, retourne false
}

std::string Server::concatenateNames(std::string channelName)
{
    std::string result;
    std::map<int, std::string>& clients = ChannelMap[channelName]->_clientInChannel;
    std::map<int, std::string>::iterator it = clients.begin();

    // Utilisation d'un booléen pour vérifier si c'est le premier élément
    bool isFirst = true;
    while (it != clients.end())
    {
        if (!isFirst)
            result += " ";
        else
            isFirst = false;

        // Vérification si le nom de l'utilisateur est l'opérateur
        if (ChannelMap[channelName]->isClientOperator(it->second))
            result += "@";
        result += it->second;
        // Déplacer l'incrémentation de l'itérateur à la fin de la boucle
        ++it;
    }
    return result;
}

void Server::send_msgs(std::string channel, std::string message, int sender, int senderIncluded)
{
    // Récupérer l'itérateur pour le canal spécifié
    std::map<std::string, Channel*>::iterator it = ChannelMap.find(channel);

    // Vérifier si le canal existe dans la map
    if (it != ChannelMap.end())
    {
        // Parcourir la map des utilisateurs du canal
        std::map<int, std::string>& clients = it->second->_clientInChannel;
        for (std::map<int, std::string>::iterator client_it = clients.begin(); client_it != clients.end(); ++client_it)
        {
            // Vérifier si l'utilisateur n'est pas l'expéditeur
            if (client_it->first != sender)
                send_msg(client_it->first, message);
            else if (senderIncluded == 1)
                send_msg(client_it->first, message);
        }
    }
}

bool Server::userExists(const std::string& nickToCheck)
{
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (_client_socket[i]._Nick == nickToCheck) {
            return true; // L'utilisateur existe avec le Nick donné
        }
    }
    return false; // L'utilisateur n'a pas été trouvé dans le tableau
}

int Server::getTabClientSocketByNick(const std::string& nickToCheck)
{
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (_client_socket[i]._Nick == nickToCheck) {
            return _client_socket[i]._tab_client_Socket; // Renvoie _tab_client_Socket si le Nick correspond
        }
    }
    return -1; // Renvoie -1 si le Nick n'est pas trouvé
}
