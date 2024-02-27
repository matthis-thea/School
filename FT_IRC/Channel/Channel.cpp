/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:25:37 by tserdet           #+#    #+#             */
/*   Updated: 2024/02/20 10:42:09 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"
#include "./../Utils_Server/Utils_and_message.hpp"

Channel::Channel(std::string Name, int Operator, std::string OperatorName)
{
    this->_name = Name;
    this->_operators.insert(Operator);
    this->_ClientsNumber = 0;
    this->_maxClient = 2;
    this->_operatorName.insert(OperatorName);
    this->_key = "";
    this->_topicRestriction = 0;
    this->_invitationMode = 0;
}

Channel::Channel(const Channel &src)
{
	*this = src;
}

Channel::Channel() {}

Channel& Channel::operator=(const Channel &src)
{
	if ( this != &src )
		return *this;
	return *this;
}

Channel::~Channel()
{

}

std::string Channel::getName() const
{
    return(this->_name);
}

std::string Channel::getTopic() const
{
    return(this->_topic);
}

std::set<std::string> Channel::getOperatorName() const
{
    return(this->_operatorName);
}

int Channel::getClientNumber() const
{
    return(this->_ClientsNumber);
}

int Channel::getMaxClient() const
{
    return(this->_maxClient);
}

std::string Channel::getKey() const
{
    return(this->_key);
}

std::set<int> Channel::getOperatorId() const
{
    return(this->_operators);
}

int Channel::getIdByName(std::string value)
{
    std::map<int, std::string>::const_iterator it;
    for (it = _clientInChannel.begin(); it != _clientInChannel.end(); ++it) {
        if (it->second == value) {
            return it->first; // Retourne la clé correspondante à la valeur
        }
    }
    return -1; // Retourne une valeur spéciale si la valeur n'est pas trouvée
}

int Channel::getTopicRestriction()
{
    return this->_topicRestriction;
}

void Channel::setTopic(std::string value)
{
    this->_topic = value;
}

void Channel::setKey(std::string value)
{
    this->_key = value;
}

void Channel::setI(bool value)
{
    this->_invitationMode = value;
}

int Channel::getI() const
{
    return(this->_invitationMode);
}

void Channel::setTopicRestriction(int value)
{
    this->_topicRestriction = value;
}

void Channel::addOperator(std::string name, int id)
{
    this->_operatorName.insert(name);
    this->_operators.insert(id);
    std::cout << GRN << "Client " << id << " named " << name << " is now operator" << NC << "\n";
}

void Channel::removeOperator(std::string name, int id)
{
    this->_operatorName.erase(name);
    this->_operators.erase(id);
    std::cout << RED << "Client " << id << " named " << name << " is not operator anymore" << NC << "\n";
}

void Channel::addClient(int idClient, const std::string& clientName)
{
    this->_clientInChannel.insert(std::make_pair(idClient, clientName));
    this->_ClientsNumber++;
    std::cout << GRN << "Client " << idClient << " named " << clientName << " is added to " << this->_name << NC << "\n";
}

void Channel::removeClient(int idClient, const std::string& clientName)
{
    this->_clientInChannel.erase(idClient);
    this->_ClientsNumber--;
    std::cout << RED << "Client " << idClient << " named " << clientName << " is removed from " << this->_name << NC << "\n";
}

void Channel::setMaxClient(int value)
{
    this->_maxClient = value;
}

void Channel::listClients() const
{
    std::cout << "Names of Clients in channel " << this->_name << ":\n";

    std::map<int, std::string>::const_iterator it;
	for (it = this->_clientInChannel.begin(); it != this->_clientInChannel.end(); ++it)
    {
        if(this->_operators.find(it->first) != this->_operators.end())
            std::cout << "°" << it->first << " - " << it->second << " (operator)"<< "\n";
        else
            std::cout << "°" << it->first << " - " << it->second << "\n";
    }

}

void Channel::listOperatorsID()const
{
    std::cout << "Liste des ID d'opérateurs :" << std::endl;
    for (std::set<int>::const_iterator it = _operators.begin(); it != _operators.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void Channel::listOperatorsName()const
{
    std::cout << "Liste des Noms d'opérateurs :" << std::endl;
    for (std::set<std::string>::const_iterator it = _operatorName.begin(); it != _operatorName.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

bool Channel::isClientInChannel(int clientX)
{
    // Parcours de la map pour vérifier si la clé clientX existe
    std::map<int, std::string>::const_iterator it;
    for (it = this->_clientInChannel.begin(); it != this->_clientInChannel.end(); ++it) {
        if (it->first == clientX) {
            return true; // Si trouvé, retourne true
        }
    }
    return false; // Si non trouvé, retourne false
}

bool Channel::isClientOperator(std::string client)
{
    return (_operatorName.find(client) != _operatorName.end());
}

bool Channel::isIdOperator(int client)
{
    return (_operators.find(client) != _operators.end());
}
