/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PRIVMSG.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:52:07 by mthea             #+#    #+#             */
/*   Updated: 2024/02/20 13:12:51 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Server/server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

void Server::privmsg(std::vector<std::string> buffer_vector, int i, int client_pos)
{
    (void) client_pos;
    (void) i;
    (void) buffer_vector;
    // std::vector<std::string> list_name_channel;
    // std::vector<std::string> message;
    // int booleann_virgule = 0;
    
}

void Server::privmsg_netcat(std::string BufferString, int i, int client_pos)
{
    (void) i;
    (void) client_pos;
    std::vector<std::string> buffer_vector = splitString(BufferString, " "); // Split the string at the space
    if (buffer_vector.size() >= 3)
    {
        std::vector<std::string> buffer_names_channels = splitString(buffer_vector[1], ","); // Split the buffer on the first occurence for recup the names
        std::string message_send;
        int existing_client = 0;
        for (size_t incr = 2; incr < buffer_vector.size(); incr++) // Recreate the messages
        {
            if (incr + 1 == buffer_vector.size())
                message_send.append(buffer_vector[incr]);
            else
            {
                message_send.append(buffer_vector[incr]);
                message_send.append(" ");
            }
        }
        if (buffer_names_channels[0].empty()) // Verify if there is a client
            send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_NORECIPENT(_client_socket[client_pos]._Nick));
        if (message_send.empty()) // Verify if the text are empty
        {
            send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_NOTEXTTOSEND(_client_socket[client_pos]._Nick));
            return ;
        }
        for (size_t incr = 1; incr < buffer_names_channels.size(); incr++) // Verification for the doublon
        {
            if (buffer_names_channels[0].compare(buffer_names_channels[incr]) == 0)
            {
                send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_TOOMANYTARGETS(buffer_names_channels[0]));
                return ;
            }
        }
        for (size_t j = 0; j < buffer_names_channels.size(); j++) // Boucle for send messages in channels or names
        {
            if (buffer_names_channels[j][0] == '#') // For channels
            {
                std::cout << "Nom du channel -----" << buffer_names_channels[j] << "-----" << std::endl;
                if(_findChannel(buffer_names_channels[j]) == false) // si channel n'existe pas encore, en créer un
                {
                    std::cout << "Channel non existant -----" << buffer_names_channels[j] << "-----" << std::endl;
                    send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_NOSUCHNICK(_client_socket[client_pos]._Nick, buffer_names_channels[j]));
                }
                else // si channel existe déjà, rejoindre
                {
                    std::cout << "Channel existant " << buffer_names_channels[j] << std::endl;
                    if (ChannelMap[buffer_names_channels[j]]->isClientInChannel(client_pos + 4) == true)
                        send_msgs(buffer_names_channels[j],  PRIVMSG(_client_socket[client_pos]._Nick , buffer_names_channels[j], message_send), client_pos + 4, 0);
                    else
                        send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_CANNOTSENDTOCHAN(_client_socket[client_pos]._Nick, buffer_names_channels[j]));
                }
            }
            else
            {
                for (int z = 0; z < MAX_CLIENTS; z++)
                {
                    if (_client_socket[z]._Nick.compare(buffer_names_channels[j]) == 0)
                    {
                        send_msg(_client_socket[z]._tab_client_Socket, PRIVMSG(_client_socket[client_pos]._Nick , _client_socket[z]._Nick, message_send));
                        std::cout << "Message envoyes" << std::endl;
                        existing_client = 1;
                    }
                }
                if (existing_client == 0)
                {
                    send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_NOSUCHNICK(_client_socket[client_pos]._Nick, buffer_names_channels[j]));
                    std::cout << "Message non envoyes" << std::endl;
                }
                existing_client = 0;
            }
            std::cout << "Valeur de buffer names channels " << buffer_names_channels[j] << std::endl;
        }
    }
    
}