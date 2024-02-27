/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:23:24 by tserdet           #+#    #+#             */
/*   Updated: 2024/02/20 10:42:26 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP
#include "../Server/server.hpp"

class Channel
{
	public:
		Channel(std::string Name, int Operator, std::string OperatorName);
		Channel(const Channel &src);
		Channel& operator=(const Channel &src);
		~Channel();
        Channel();
        void listClients() const;//affiche les clients present dans le channell sur la console du serveur
        void listOperatorsID()const;//affiche les ID d'operateurs present dans le channell sur la console du serveur
        void listOperatorsName()const;//affiche les noms d'operateurs present dans le channell sur la console du serveur
        std::string getName() const;//donne le nom du channel
        int getClientNumber() const;//donne le nombre de client
        int getMaxClient() const;//donne le nombre maximal de client autorisé dans ce channel
        std::string getTopic() const;//donne le topic du channel
        std::set<std::string> getOperatorName() const;//donne le nom de l'operateur
        std::set<int> getOperatorId()const;//donnne l'id de l'operator
        bool isClientOperator(std::string client);//dis si le client donne est un operateur
        void addClient(int idClient, const std::string& clientName);//ajoute un client au channel
        void addOperator(std::string name, int id);//ajoute le nom et l'id d'un nouvel utilisateurs aux listes
        void removeOperator(std::string name, int id);//retire le nom et l'id d'un nouvel utilisateurs aux listes
        void removeClient(int idClient, const std::string& clientName);//enleve un client du channel
        void setMaxClient(int value); //definit le nombre maximmum de client dans le channel
        void setTopic(std::string value); //definit le topic du channel
        void setTopicRestriction(int value); //autorise les operateurs ou non a changer le topic
        bool isClientInChannel(int clientX); //dis si le client est dans le channel
        bool isIdOperator(int client);//dis si l'id est un operator
        int getIdByName(std::string value);//retourne l'id d'un client avec son nom
        int getTopicRestriction(); //retourne si la restriction moderateur du topic est active
        std::string getKey() const; // retourne la cle du channel
        int getI() const;//retourne si le canal est en invitation mode
        void setKey(std::string value); // definit la cle du channel
        void setI(bool value);//definit le canal sur invitation ou non
        std::map<int, std::string> _clientInChannel; // container IDclient|nom Client dans le channel

    private:
        std::string _name; //nom channel
        std::string _topic; //topic channel
        std::set<std::string> _operatorName;//name operator
        std::string _key; //cle du channel
        std::set<int> _operators; //id operator
        int _ClientsNumber; //nombre de clients connecte
        int _maxClient; //client max qui peuvent rejoindre
        int _topicRestriction; //Mode T
        int _invitationMode;//Mode I
};
#endif
