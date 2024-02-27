/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:24:48 by mthea             #+#    #+#             */
/*   Updated: 2024/02/20 12:56:02 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./server.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

Server::Server(std::string Port, std::string Password): _Port(Port), _Password(Password)
{
	_currentTime = std::time(0);

    // Convertir le temps en une chaîne lisible
    _timeString = std::ctime(&_currentTime);
}


Server::Server(const Server &src)
{
	*this = src;
}

Server& Server::operator=(const Server &src)
{
	if ( this != &src )
		return *this;
	return *this;
}

Server::~Server()
{

}

void Server::_listChannels()
{
    std::cout << "Names of channels already created:\n";
    
    std::map<std::string, Channel *>::const_iterator it;
    for (it = ChannelMap.begin(); it != ChannelMap.end(); ++it) {
        std::cout << it->second->getName() << "\n";
    }
}

void Server::reset_client(int client_pos)
{
    _client_socket[client_pos]._tab_client_Socket = 0;
    _client_socket[client_pos]._ip_address.clear();
    _client_socket[client_pos]._ip_port = 0;
    _client_socket[client_pos]._Pass.clear();
	_client_socket[client_pos]._Nick.clear();
	_client_socket[client_pos]._User.clear();
	_client_socket[client_pos]._Realname.clear();
	_client_socket[client_pos].boolean_connected = 0;
    _client_socket[client_pos].invitations.clear();
}

void Server::verification_finale(int client_pos)
{
	if (!_client_socket[client_pos]._Pass.empty() && !_client_socket[client_pos]._Nick.empty() && !_client_socket[client_pos]._User.empty() && !_client_socket[client_pos]._Realname.empty())
	{
		if (_client_socket[client_pos]._Pass.compare(_Password) == 0)
		{
			_client_socket[client_pos].boolean_connected = 1;
			_client_socket[client_pos].boolean_message = 1;
		}
        else
        {
            send_msg(_client_socket[client_pos]._tab_client_Socket, ERR_PASSWDMISMATCH(_client_socket[client_pos]._Pass));
            _client_socket[client_pos].boolean_password = 0;
            _client_socket[client_pos].boolean_nick = 0;
            _client_socket[client_pos].boolean_user = 0;
            _client_socket[client_pos].boolean_nick_inuse = 0;
            _client_socket[client_pos].boolean_nick_error = 0;
            _client_socket[client_pos].boolean_connected = 0;
            _client_socket[client_pos]._Pass.clear();
            _client_socket[client_pos]._Nick.clear();
            _client_socket[client_pos]._User.clear();
            _client_socket[client_pos]._Realname.clear();
        }
	}
	if (_client_socket[client_pos].boolean_message == 1)
	{
		send_msg(_client_socket[client_pos]._tab_client_Socket, RPL_WELCOME(_client_socket[client_pos]._Nick, "Irc_Serv_Thib_Mat", _client_socket[client_pos]._Nick, _client_socket[client_pos]._User));
		send_msg(_client_socket[client_pos]._tab_client_Socket, RPL_YOURHOST(_client_socket[client_pos]._Nick, "Irc_Serv_Thib_Mat", "1.2.4"));
		send_msg(_client_socket[client_pos]._tab_client_Socket, RPL_CREATED(_client_socket[client_pos]._Nick, _timeString));
		send_msg(_client_socket[client_pos]._tab_client_Socket, RPL_MYINFO(_client_socket[client_pos]._Nick, "Irc_Serv_Thib_Mat", "1.2.4", "oOiwscrknfbghexzSjFI", "bhijklmMnoOstvcdSuU", "bkohv"));
		send_msg(_client_socket[client_pos]._tab_client_Socket, RPL_ISUPPORT(_client_socket[client_pos]._Nick, "1tokzn"));
		// send_msg(_client_socket[client_pos]._tab_client_Socket, RPL_UMODEIS(_client_socket[client_pos]._Nick, "1"));
        send_msg(_client_socket[client_pos]._tab_client_Socket, RPL_MOTDSTART(_client_socket[client_pos]._Nick, "Irc_Serv_Thib_Mat"));
        send_msg(_client_socket[client_pos]._tab_client_Socket, RPL_MOTD(_client_socket[client_pos]._Nick, "Irc_Serv_Thib_Mat"));
        send_msg(_client_socket[client_pos]._tab_client_Socket, RPL_ENDOFMOTD(_client_socket[client_pos]._Nick));
		std::cout << GRN << "Nick " << NC << RED << _client_socket[client_pos]._Nick << NC <<  GRN << " connection accepted" << NC << std::endl << std::endl;
	}
	_client_socket[client_pos].boolean_message = 0;
	// std::cout << "Ca rentre Ca rentre" << std::endl;
}

void Server::init_connection_client(int client_pos, char buffer[1024])
{
    std::vector<std::string> buffer_vector;
    std::string buffer_transfert;
    std::string delimiter = " ";
    std::string buffer_string = buffer;
    size_t position = buffer_string.find('\r'); // FInd the position of the back slash '\r'

    if (position != std::string::npos) // The string contains the '\r'
    {
        buffer_transfert = joinString(buffer_string, "\r\n"); // Split "\r\n" in string buffer transfert
        buffer_vector = splitString(buffer_transfert, " "); // Split " " in buffer_transfer in buffer_vector
        for (size_t i = 0; i < buffer_vector.size(); i++) 
        {
            if (buffer_vector[i].compare("PASS") == 0) // Put the PASS messages in side clients
            {
				verification_Pass(buffer_vector, i, client_pos);
            }
            if (buffer_vector[i].compare("NICK") == 0)  // Put the NICK messages in side clients
            {
				verification_Nick(buffer_vector, i, client_pos);
            }
            if (buffer_vector[i].compare("USER") == 0)  // Put the NICK messages in side clients
            {
				verification_User(buffer_vector, i, client_pos);
            }
        }
		verification_finale(client_pos);
    }
    else // The string not contains the '\r'
    {
        buffer_transfert = joinString(buffer_string, "\n"); // Split "\r\n" in string buffer transfert
        buffer_vector = splitString(buffer_transfert, " "); // Split " " in buffer_transfer in buffer_vector
        for (size_t i = 0; i < buffer_vector.size(); i++) 
        {
            if (buffer_vector[i].compare("PASS") == 0 && (i + 1 < buffer_vector.size()) && _client_socket[client_pos].boolean_password == 0) // Put the PASS messages in side clients
            {
				verification_Pass(buffer_vector, i, client_pos);
				_client_socket[client_pos].boolean_nick = 1;
            }
            if (buffer_vector[i].compare("NICK") == 0 && (i + 1 < buffer_vector.size()) && _client_socket[client_pos].boolean_nick == 1)  // Put the NICK messages in side clients
            {
				verification_Nick(buffer_vector, i, client_pos);
				_client_socket[client_pos].boolean_password = 1;
				_client_socket[client_pos].boolean_user = 2;
            }
            if (buffer_vector[i].compare("USER") == 0 && (i + 1 < buffer_vector.size()) && (i + 2 < buffer_vector.size()) && _client_socket[client_pos].boolean_user == 2)  // Put the NICK messages in side clients
            {
				verification_User(buffer_vector, i, client_pos);
				_client_socket[client_pos].boolean_nick = 2;
            }
        }
		verification_finale(client_pos);
    }
}

void Server::start_server(void)
{
    //------------------------------------------------------------------------
	int master_socket = 0;
	int opt = true;
	sockaddr_in address;
	int addrlen = 0;
	int sd = 0;
	int max_sd = 0;
	int activity = 0;
	int new_socket = 0;
	int valread = 0;
	char buffer[1024];
	//set of socket descriptors  
    fd_set readfds;  
	//-------------------------------------------------------------------------

	if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) //create a master socket 
		throw::std::logic_error("Socket failed\n");

	if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0) //set master socket to allow multiple connections
		throw::std::logic_error("Setsockopt failed\n");

	address.sin_family = AF_INET;   //type of socket created  
    address.sin_addr.s_addr = INADDR_ANY;   //type of socket created

	const char *char_por_cast = _Port.c_str();
	uint16_t port_cast = static_cast<uint16_t>(std::atoi(char_por_cast));
    address.sin_port = htons(port_cast);      //type of socket created

	if (bind(master_socket, reinterpret_cast<struct sockaddr*>(&address), sizeof(address)) == -1)
	{
		//bind the socket to localhost port n
		perror("Bind error");
		close(master_socket);
		throw::std::logic_error("Bind error !\n");
	}  

	if (listen(master_socket, 5) < 0) //try to specify maximum of 3 pending connections for the master socket  
		throw::std::logic_error("Listen error\n");

	addrlen = sizeof(address);   //accept the incoming connection

	std::cout << "Waiting connections on port " << port_cast << std::endl;

	while (true)
	{
		//clear the socket set  
        FD_ZERO(&readfds);

		 //add master socket to set  
        FD_SET(master_socket, &readfds);   
        max_sd = master_socket;
		for (int i = 0 ; i < MAX_CLIENTS; i++)   
        {   
            //socket descriptor  
            sd = _client_socket[i]._tab_client_Socket;
                 
            //if valid socket descriptor then add to read list  
            if(sd > 0)   
                FD_SET( sd , &readfds);   
                 
            //highest file descriptor number, need it for the select function  
            if(sd > max_sd)   
                max_sd = sd;   
        }

		 //wait for an activity on one of the sockets , timeout is NULL ,  
        //so wait indefinitely  
        activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);    
        if ((activity < 0) && (errno != EINTR))
            throw::std::logic_error("select error !\n");

		if (FD_ISSET(master_socket, &readfds))   
        {   
            if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)   
             throw::std::logic_error("accept error !\n");
             
            //inform user of socket number - used in send and receive commands 
			// std::cout << "New connection , socket fd is " << new_socket << ", ip is : " << inet_ntoa(address.sin_addr) << ", port : " << ntohs(address.sin_port) << std::endl; 

            //send new connection greeting message 
			// std::string message_test = "Hello world !";
            // if (send(new_socket, message_test, message_test.size(), 0) < 0)
	 		// 	throw::std::logic_error("send error !\r\n");   

            //add new socket to array of sockets  
            for (int i = 0; i < MAX_CLIENTS; i++)   
            {   
                //if position is empty  
                if ( _client_socket[i]._tab_client_Socket == 0 )   
                {   
                    _client_socket[i]._tab_client_Socket = new_socket;
					_client_socket[i]._ip_address = inet_ntoa(address.sin_addr);
					_client_socket[i]._ip_port = ntohs(address.sin_port);
                    // std::cout << "Adding to list of sockets as " << i << std::endl;                       
                    break;   
                }   
            }

        }
		//else its some IO operation on some other socket 
        for (int i = 0; i < MAX_CLIENTS; i++)   
        {   
            sd = _client_socket[i]._tab_client_Socket;   
                 
            if (FD_ISSET( sd , &readfds))   
            {   
                //Check if it was for closing , and also read the  
                //incoming message 
                if ((valread = read(sd , buffer, 1024)) <= 0)   
                {   
                    //Somebody disconnected , get his details and print  
                    getpeername(sd , (struct sockaddr*)&address , (socklen_t*)&addrlen);
					std::cout << GRN << "Nick " << NC << RED << _client_socket[i]._Nick << NC <<  GRN << " disconnected" << NC << std::endl << std::endl;       
                    close(sd); //Close the socket and mark as 0 in list for reuse 
                    quit(sd, i, "");
                    reset_client(i);  // Reuse the client
                }          
                //Echo back the message that came in  
                else 
                {
                    
                    buffer[valread] = '\0';
                    if (valread >= 513)
                    {
                        send_msg(sd, ERR_INPUTTOOLONG(_client_socket[i]._Nick));
                    }
					if (_client_socket[i].boolean_connected == 0)
                    	init_connection_client(i, buffer);
					else if (_client_socket[i].boolean_connected == 1)
					{
                        //THIB---------------------------------------------------------------------------------------------------------
						std::string bufferString = buffer;
                        size_t position = bufferString.find('\r'); // FInd the position of the back slash '\r'
                        if (position != std::string::npos) // The string contains the '\r'
                        {
                            buffer[valread - 2] = '\0';
                        }
                        else
                        {
                            buffer[valread - 1] = '\0';
                        }
                        bufferString = buffer;
						std::cout << "Client ip " << sd << " sent message at port " << _client_socket[i]._ip_port << ": " << buffer << "\n";
						std::vector<std::string> buffer_vector = splitString(bufferString, " ");
                        if (buffer_vector[0].compare("JOIN") == 0 || buffer_vector[0].compare("/join") == 0 )//JOIN COMMAND
                        {
                            if (buffer_vector.size() == 2)
                            {
                                if (buffer_vector[1][0] != '#')
                                    buffer_vector[1] = "#" + buffer_vector[1];
                                join(buffer_vector[1], sd, i, "");
                            }
                            else if (buffer_vector.size() == 3)
                            {
                                if (buffer_vector[1][0] != '#')
                                    buffer_vector[1] = "#" + buffer_vector[1];
                                join(buffer_vector[1], sd, i, buffer_vector[2]);
                            }
                            else if (buffer_vector.size() < 2)//si < 2 parametres
                                send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "JOIN"));
                        }
                        else if (buffer_vector[0].compare("PART") == 0 || buffer_vector[0].compare("/part") == 0 )//PART COMMAND
                        {
                            if (buffer_vector.size() >= 3)
                            {
                                if (buffer_vector[1][0] != '#')
                                    buffer_vector[1] = "#" + buffer_vector[1];
                                part(buffer_vector[1], buffer_vector[2], sd, i);
                            }
                            else if (buffer_vector.size() < 3)//si < 3 parametres
                                send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "PART"));
                        }
                        else if (buffer_vector[0].compare("KICK") == 0 || buffer_vector[0].compare("/kick") == 0 )//KICK COMMAND
                        {
                            if (buffer_vector.size() >= 4)
                            {
                                if (buffer_vector[1][0] != '#')
                                    buffer_vector[1] = "#" + buffer_vector[1];
                                kick(buffer_vector[1], buffer_vector[3], sd, ChannelMap[buffer_vector[1]]->getIdByName(buffer_vector[2]), i);
                            }
                            else if (buffer_vector.size() < 4)//si < 4 parametres
                                send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "KICK"));
                        }
                        else if (buffer_vector[0].compare("TOPIC") == 0 || buffer_vector[0].compare("/topic") == 0 )//TOPIC COMMAND
                        {
                            if (buffer_vector.size() >= 2)
                            {
                                if (buffer_vector[1][0] != '#')
                                    buffer_vector[1] = "#" + buffer_vector[1];
                                if (buffer_vector.size() == 2)
                                    topicShow(buffer_vector[1], sd, i);
                                else if (buffer_vector.size() == 3)
                                    topicSet(buffer_vector[1], buffer_vector[2], sd, i);
                            }
                            else if (buffer_vector.size() < 2)//si < 2 parametres
                                send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "TOPIC"));
                        }
                        else if (buffer_vector[0].compare("INVITE") == 0 || buffer_vector[0].compare("/invite") == 0 )//INVITE COMMAND
                        {
                            if (buffer_vector.size() >= 3)
                            {
                                if (buffer_vector[2][0] != '#')
                                    buffer_vector[2] = "#" + buffer_vector[1];
                                invite(buffer_vector[2], sd, i, buffer_vector[1]);
                            }
                            else if (buffer_vector.size() < 3)//si < 3 parametres
                                send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "INVITE"));
                        }
                        else if (buffer_vector[0].compare("QUIT") == 0 || buffer_vector[0].compare("/quit") == 0 )//QUIT COMMAND
                        {
                            if (buffer_vector.size() >= 2)
                            {
                                close(sd);
                                quit(sd, i, buffer_vector[1]);
                                reset_client(i);
                            }
                            else if (buffer_vector.size() < 2)//si < 2 parametres
                                send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "QUIT"));
                        }
                        else if (buffer_vector[0].compare("MODE") == 0 || buffer_vector[0].compare("/mode") == 0 )//MODE COMMAND
                        {
                            if (buffer_vector.size() > 2)
                            {
                                if (buffer_vector[1][0] != '#')
                                    buffer_vector[1] = "#" + buffer_vector[1];
                                if (buffer_vector[2][1] == 'l' && buffer_vector.size() >= 3)//MODE L
                                {
                                    if(buffer_vector[2][0] == '+' && buffer_vector.size() == 3)
                                        send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "MODE"));
                                    else
                                        modeL(buffer_vector[1], sd, i, buffer_vector[2][0], buffer_vector[3]);
                                }
                                else if (buffer_vector.size() < 3)//si < 3 parametres
                                    send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "MODE"));
                                if (buffer_vector[2][1] == 'o' && buffer_vector.size() >= 4)//MODE O
                                    modeO(buffer_vector[1], sd, i, buffer_vector[2][0], buffer_vector[3]);
                                else if (buffer_vector.size() < 4)//si < 4 parametres
                                    send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "MODE"));
                                if (buffer_vector[2][1] == 't' && buffer_vector.size() >= 3)//MODE T
                                    modeT(buffer_vector[1], sd, i, buffer_vector[2][0]);
                                else if (buffer_vector.size() < 3)//si < 3 parametres
                                    send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "MODE"));
                                if (buffer_vector[2][1] == 'k' && buffer_vector.size() >= 3)//MODE L
                                {
                                    if(buffer_vector[2][0] == '+' && buffer_vector.size() == 3)
                                        send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "MODE"));
                                    else
                                        modeK(buffer_vector[1], sd, i, buffer_vector[2][0], buffer_vector[3]);
                                }
                                if (buffer_vector[2][1] == 'i' && buffer_vector.size() >= 3)//MODE I
                                    modeI(buffer_vector[1], sd, i, buffer_vector[2][0]);
                                else if (buffer_vector.size() < 3)//si < 3 parametres
                                    send_msg(sd, ERR_NEEDMOREPARAMS(_client_socket[i]._ip_address, "MODE"));
                            }
                        }
						else if ((buffer_vector[0].compare("PASS") == 0 || buffer_vector[0].compare("/pass") == 0) && buffer_vector.size() > 0)
						{
							verification_Pass(buffer_vector, 0, i);
						}
						else if ((buffer_vector[0].compare("NICK") == 0 || buffer_vector[0].compare("/nick") == 0) && buffer_vector.size() > 0)
						{
							verification_Nick(buffer_vector, 0, i);
						}
						else if ((buffer_vector[0].compare("USER") == 0 || buffer_vector[0].compare("/user") == 0) && buffer_vector.size() > 0)
						{
							verification_User(buffer_vector, 0, i);
						}
                        else if ((buffer_vector[0].compare("PING") == 0 || buffer_vector[0].compare("/ping") == 0) && buffer_vector.size() > 0)
                        {
                                if (buffer_vector.size() == 1)
		                            send_msg(_client_socket[i]._tab_client_Socket, ERR_NEEDMOREPARAMS(_client_socket[i]._Nick, "PING"));
                                else
                                    Pong(buffer_vector, 0, i);
                        }
                        else if ((buffer_vector[0].compare("PRIVMSG") == 0 || buffer_vector[0].compare("/msg") == 0) && buffer_vector.size() > 0)
                        {
                            // if (buffer_vector[0].compare("/msg") == 0)
                            privmsg_netcat(bufferString, 0, i);
                            // else
                            //     privmsg(buffer_vector, 0, i);
                            
                        }
                        
					}
                    buffer[0] = '\0'; // For clear the buffer
                    // std::cout << "clear buffer" << std::endl;
                }   
            }    
		}
	}
}