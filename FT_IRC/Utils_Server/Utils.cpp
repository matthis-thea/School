/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:12:06 by haze              #+#    #+#             */
/*   Updated: 2024/02/19 06:44:34 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Utils_and_message.hpp"
#include "./../Client/Client_Socket.hpp"

std::vector<std::string> vectorSplit(const std::string& str, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void send_msg(int socket, std::string message)
{
	send(socket, message.c_str(), message.size(), 0);
}


bool verification_virgule(std::vector<std::string> buffer_vector)
{
    for (size_t taille = 1; taille < buffer_vector.size(); taille++) 
    {
        if (buffer_vector[taille].compare(",") == 0 && buffer_vector[taille - 1].compare("\\") != 0)
            return (true);
    }
    return (false);
}

std::string joinString(const std::string& input, const std::string& delimiter)
{
    std::string result;
    size_t start = 0, end = 0;

    while ((end = input.find(delimiter, start)) != std::string::npos)
    {
        result += input.substr(start, end - start) + " ";
        start = end + delimiter.length();
    }

    // Ajouter la dernière sous-chaîne après le dernier délimiteur
    result += input.substr(start);

    return result;
}

std::vector<std::string> splitString(const std::string& input, const std::string& delimiter) 
{
    std::vector<std::string> tokens;
    size_t start = 0, end = 0;

    while ((end = input.find(delimiter, start)) != std::string::npos) 
    {
        tokens.push_back(input.substr(start, end - start));
        start = end + delimiter.length();
    }

    // Ajouter la dernière sous-chaîne après le dernier délimiteur
    tokens.push_back(input.substr(start));

    return tokens;
}