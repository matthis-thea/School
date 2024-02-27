/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client_Socket.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:12:35 by mthea             #+#    #+#             */
/*   Updated: 2024/02/20 10:42:59 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLIENT_SOCKET_HPP
#define CLIENT_SOCKET_HPP
#define MAX_CLIENTS 50
#define USERLEN 15
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

class Client_Socket
{
	public:
		Client_Socket();
		Client_Socket(const Client_Socket &src);
		Client_Socket& operator=(const Client_Socket &src);
		~Client_Socket();
		int _tab_client_Socket;
		std::string _ip_address;
		uint16_t _ip_port;
		std::string _Nick;
		int boolean_nick_inuse;
		int boolean_nick_error;
		int boolean_nick;
		std::string _User;
		std::string _Realname;
		int boolean_user;
		std::string _Pass;
		int boolean_password;
		int boolean_message;
		int boolean_connected;
		//THIB------------------------
		std::vector<std::string> invitations;
		bool isChannelPresent(const std::string& channelToFind);

	private:
	class ErrorServer : public std::exception
	{
		public:
			const char* what() const throw();
	};


};
#endif