/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:55:14 by haze              #+#    #+#             */
/*   Updated: 2023/12/17 15:54:34 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange& operator=(const BitcoinExchange &src);
		~BitcoinExchange();
		void Open_Csv(const std::string &filename);
		void Open_txt(const std::string &filename);
		int	Verification_date(const std::string &date);
		double Verification_date_limite(const std::string &date);
		class ErrorFile : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class ErrorDelimiter : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class ErrorValue : public std::exception
		{
			public:
				const char* what() const throw();
		};
	private:
		std::map<std::string, double> _tab;

};