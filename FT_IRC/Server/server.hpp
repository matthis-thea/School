/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:24:45 by mthea             #+#    #+#             */
/*   Updated: 2024/02/20 10:45:12 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP
#include <iostream>
#include <cstring>
#include <string>
#include <cerrno>
#include <cstdlib>
#include <unistd.h>
#include <vector>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <bits/stdc++.h>
#include <cctype>
#include "./../Client/Client_Socket.hpp"
#include "../Channel/Channel.hpp"


class Channel;

class Server
{
	public:
		Server(std::string Port, std::string Password);
		Server(const Server &src);
		Server& operator=(const Server &src);
		~Server();
		void start_server(void);
		void verification_finale(int client_pos);
		void verification_Pass(std::vector<std::string> buffer_vector, int i, int client_pos);
		void verification_Nick(std::vector<std::string> buffer_vector, int i, int client_pos);
		void verification_User(std::vector<std::string> buffer_vector, int i, int client_pos);
		void privmsg(std::vector<std::string> buffer_vector, int i, int client_pos);
		void privmsg_netcat(std::string BufferString, int i, int client_pos);
		void Pong(std::vector<std::string> buffer_vector, int i, int client_pos);
		void init_connection_client(int client_pos, char buffer[1024]); // Verify the messages for init the connection and connect the client
		void reset_client(int client_pos); // TO disconnect the client
		//THIB---------------------------------------------------
		void join(std::string channelName, int idClient, int i, std::string key);
		void part(std::string channelName, std::string reason,  int idClient, int i);
		void kick(std::string channelName, std::string reason,  int idClient, int idKicked, int i);
		void invite(std::string channelName, int idClient, int i, std::string invited);
		void quit(int idClient, int i, std::string reason);
		void modeL(std::string channelName,int idClient, int i, char aOd, std::string value);
		void modeO(std::string channelName,int idClient, int i, char aOd, std::string value);
		void modeT(std::string channelName,int idClient, int i, char aOd);
		void modeK(std::string channelName,int idClient, int i, char aOd, std::string value);
		void modeI(std::string channelName,int idClient, int i, char aOd);
		void topicShow(std::string channelName, int idClient, int i);
		void topicSet(std::string channelName, std::string value, int idClient, int i);
		std::string concatenateNames(std::string channelName);
		void send_msgs(std::string channel, std::string message, int sender, int senderIncluded);
		void channelExist(std::string channelName, int idClient, int i, std::string symbol);
		void inviting(std::string channelName, int i, std::string invited);
		bool userExists(const std::string& nickToCheck);
		int getTabClientSocketByNick(const std::string& nickToCheck);
	private:
		int _Server_Socket;
		std::string _Port;
		std::string _Password;
		std::time_t _currentTime;
		//THIB---------------------------------------------------
		std::map<std::string, Channel *> ChannelMap;
		bool _findChannel(std::string name);
		void _listChannels();


    // Convertir le temps en une chaîne lisible
    	std::string _timeString;
		Client_Socket _client_socket[MAX_CLIENTS];
	class ErrorServer : public std::exception
	{
		public:
			const char* what() const throw();
	};


};
#endif
