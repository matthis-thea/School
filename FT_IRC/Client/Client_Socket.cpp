/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client_Socket.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:12:38 by mthea             #+#    #+#             */
/*   Updated: 2024/02/20 10:42:48 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Client_Socket.hpp"

Client_Socket::Client_Socket()
{ 
	_tab_client_Socket = 0;
	boolean_password = 0;
	boolean_nick = 0;
	boolean_user = 0;
	boolean_nick_inuse = 0;
	boolean_nick_error = 0;
	boolean_connected = 0;
}


Client_Socket::Client_Socket(const Client_Socket &src)
{
	*this = src;
}

Client_Socket& Client_Socket::operator=(const Client_Socket &src)
{
	if ( this != &src )
		return *this;
	return *this;
}

Client_Socket::~Client_Socket()
{

}

bool Client_Socket::isChannelPresent(const std::string& channelToFind)
{
    // Itérateur pour parcourir le vecteur
    std::vector<std::string>::const_iterator it;
    for (it = invitations.begin(); it != invitations.end(); ++it) {
        if (*it == channelToFind) {
            return true; // Le channel est présent dans le conteneur
        }
    }
    return false; // Le channel n'est pas présent dans le conteneur
}
