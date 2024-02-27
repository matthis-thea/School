/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils_and_message.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:18:07 by mthea             #+#    #+#             */
/*   Updated: 2024/02/20 11:32:58 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_AND_MESSAGE_HPP
#define UTILS_AND_MESSAGE_HPP
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
#include <ctime>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define GRNB "\033[1;32m"

// For Pass message
# define ERR_NEEDMOREPARAMS(client, commande) (":Irc_Serv_Thib_Mat 461 " + client + " " + commande + " :Not enough parameters\r\n") // 461
# define ERR_ALREADYREGISTERED(client) (":Irc_Serv_Thib_Mat 462 " + client + " :You may not reregister\r\n") // 462
# define ERR_PASSWDMISMATCH(client) (":Irc_Serv_Thib_Mat 464 " + client + " :Password incorrect\r\n") // 464
// For Nick message
# define ERR_NONICKNAMEGIVEN(client) (":Irc_Serv_Thib_Mat 431 " + client + " :No nickname given\r\n") // 431
# define ERR_ERRONEUSNICKNAME(client, nick) (":Irc_Serv_Thib_Mat 432 " + client + " " + nick + " :Erroneus nickname\r\n")
# define ERR_NICKNAMEINUSE(client, nick) (":Irc_Serv_Thib_Mat 433 " + client + " " + nick + " :Nickname is already in use\r\n") // 433
# define CHANGE_NICK(last_pseudo, new_pseudo) (":" + last_pseudo + " NICK " + new_pseudo + "\r\n") // Optionnel
// For init the connection
# define RPL_WELCOME(client, servername, user, host) (":Irc_Serv_Thib_Mat 001 " + client + " :Welcome to the " + servername + " Network, " + client + "!" + user + "@" + host + "\r\n") // 001
# define RPL_YOURHOST(client, servername, version) (":Irc_Serv_Thib_Mat 002 " + client + " :Your host is " + servername + ", running version " + version + "\r\n") // 002
# define RPL_CREATED(client, datetime) (":Irc_Serv_Thib_Mat 003 " + client + " :This server was created " + datetime + "\r\n") // 003
# define RPL_MYINFO(client, servername, version, avaibles_umodes, avaibles_cmodes, cmodes_with_param) (":Irc_Serv_Thib_Mat 004 " + client + " " + servername + " " + version + " " + avaibles_umodes + " " + avaibles_cmodes + " " + cmodes_with_param + "\r\n") // 004
# define RPL_ISUPPORT(client, token) (":Irc_Serv_Thib_Mat 005 " + client + " " + token + " :are supported by this server\r\n") // 005
# define RPL_UMODEIS(client, usermodes) (":Irc_Serv_Thib_Mat 221 " + client + " " + usermodes + "\r\n") // 221
// For Error message 
# define ERR_INPUTTOOLONG(client)(":Irc_Serv_Thib_Mat 417 " + client + " :Input line was too long\r\n") // 417
// For Message_of_the_day
# define RPL_MOTDSTART(client, serveur)(":Irc_Serv_Thib_Mat 375 "+ client + " :- " + serveur + " Message of the day -\r\n") // 375
# define RPL_MOTD(client, serveur)(":Irc_Serv_Thib_Mat 375 " + client + " :- Irc_Serv_Thib_Mat is a really cool network!\r\n"":Irc_Serv_Thib_Mat 375 " + client + " :- No spamming please, thank you!\r\n") // 372
# define RPL_ENDOFMOTD(client)(":Irc_Serv_Thib_Mat 376 " + client + " :- End of /MOTD command.\r\n") // 376
std::vector<std::string> splitString(const std::string& input, const std::string& delimiter);
// For Ping message
# define ERR_NOSUCHSERVER(client, servername)(":Irc_Serv_Thib_Mat 402 " + client + " " + servername + " :No such server\r\n") // 402
// For Pong message
# define PONG(token)("PONG Irc_Serv_Thib_Mat " + token + "\r\n")
// For privmsg
// # define PRIVMSG(sender, receiver, messages)(":" + sender + " PRIVMSG " + receiver + " :" + messages + "\r\n")
# define PRIVMSG(sender, receiver, msg)	(":" + sender + "@localhost PRIVMSG " + receiver + " " + msg + "\r\n")
# define ERR_TOOMANYTARGETS(receveir)(":Irc_Serv_Thib_Mat 407 " + receveir + " :Duplicate recipients. No message delivered\r\n")  // 407
# define ERR_NOSUCHNICK(client, nickname)(":Irc_Serv_Thib_Mat 401 " + client + " " + nickname + " :No such nick/channel\r\n") // 401
# define ERR_CANNOTSENDTOCHAN(client, channel)(":Irc_Serv_Thib_Mat 404 " + client + " " + channel + " :Cannot send to channel\r\n") // 404
# define ERR_NOTEXTTOSEND(client)(":Irc_Serv_Thib_Mat 412 " + client + " :No text to send\r\n") // 412
# define ERR_NORECIPENT(client)(":Irc_Serv_Thib_Mat 411 " + client + " :No recipent given\r\n") // 411
std::string joinString(const std::string& input, const std::string& delimiter);

void send_msg(int socket, std::string message);
bool verification_virgule(std::vector<std::string> buffer_vector);
// ------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------
// Thib
# define JOIN(sender, target)			(":" + sender + "@Irc_Serv_Thib_Mat JOIN " + target + "\r\n")
# define PART(sender, chan, reason)	(":" + sender + "@Irc_Serv_Thib_Mat PART " + chan + " " + reason + "\r\n")
# define KICK(sender, chan, nick, reason)(":" + sender + "@Irc_Serv_Thib_Mat KICK " + chan + " " + nick + " " + reason + "\r\n")
# define MODE(sender, target, mode, arg)	(":" + sender + "@Irc_Serv_Thib_Mat MODE " + target + " " + mode + " " + arg + "\r\n")
# define TOPIC(sender, chan, topic)		(":" + sender + "@Irc_Serv_Thib_Mat TOPIC " + chan + " " + topic + "\r\n")
# define QUIT(sender, reason)			(":" + sender + "@Irc_Serv_Thib_Mat QUIT " + reason + "\r\n")
# define INVITE(sender, target, chan)	(":" + sender + "@Irc_Serv_Thib_Mat INVITE " + target + " " + chan + "\r\n")
//ERR---------------------
# define ERR_NOSUCHCHANNEL(client, channel) (":Irc_Serv_Thib_Mat 403 " + client + " " + channel + " :No such channel\r\n") // 403
# define ERR_USERNOTINCHANNEL(client, nick, channel) (":Irc_Serv_Thib_Mat 441 " + client + " " + nick + " " + channel + " :They aren't on that channel\r\n") // 441
# define ERR_USERONCHANNEL(client, nick, chan)	(":Irc_Serv_Thib_Mat 443 " + client + " " + nick + " " + chan + " :Is already on channel\r\n")//443
# define ERR_NOTONCHANNEL(client, channel) (":Irc_Serv_Thib_Mat 442 " + client + " " + channel + " :You're not on that channel\r\n") // 442
# define ERR_CHANNELISFULL(client, channel) (":Irc_Serv_Thib_Mat 471 " + client + " " + channel + " :Cannot join channel (+l)\r\n") // 471
# define ERR_INVITEONLYCHAN(client, chan)(":Irc_Serv_Thib_Mat 473 " + client + " " + chan + " :Cannot join channel (+i)\r\n")// 473
# define ERR_BADCHANNELKEY(client, chan)	(":Irc_Serv_Thib_Mat 475 " + client + " " + chan + " :Cannot join channel (+k)\r\n")//475
# define ERR_CHANOPRIVSNEEDED(client, channel) (":Irc_Serv_Thib_Mat 482 " + client + " " + channel + " :You're not channel operator\r\n") // 482
//RPL---------------------
# define RPL_NOTOPIC(client, chan)	(":Irc_Serv_Thib_Mat 331 " + client + " " + chan + " :No topic is set\r\n")//331
# define RPL_TOPIC(client, chan, topic)	(":Irc_Serv_Thib_Mat 332 " + client + " " + chan + " :" + topic + "\r\n") //332
# define RPL_NAMREPLY(client, symbol, channel, user) (":Irc_Serv_Thib_Mat 353 " + client + " " + symbol + " " + channel + " :" + user + " \r\n") // 353
# define RPL_ENDOFNAMES(client, channel) (":Irc_Serv_Thib_Mat 366 " + client + " " + channel + " :End of /NAMES list\r\n") // 366
std::vector<std::string> vectorSplit(const std::string& str, char delimiter);
#endif