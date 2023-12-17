/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:55:27 by haze              #+#    #+#             */
/*   Updated: 2023/12/17 16:09:13 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if ( this != &src )
    	return *this;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::Open_Csv(const std::string &filename)
{
		std::ifstream flux(filename.c_str());
		if (flux)
		{
			std::string line;
			std::getline(flux, line);
			while (std::getline(flux, line))
			{
				std::size_t delimiter = line.find(',');
				if (delimiter == std::string::npos)
				{
					std::cout << "The delimiter was not found !" << std::endl;
					continue;
				}
				std::string date = line.substr(0, delimiter);
				std::string value_temp = line.substr(delimiter + 1);
				double value;
				std::istringstream iss(value_temp);
				if (!(iss >> value))
				{
					std::cout << "Error value !" << std::endl;
					exit(0);
				}
				if (!Verification_date(date))
				{
					std::cout << "Error on the date => " << date << std::endl;
					exit(0);
				}
				_tab[date] = value;
			}
		}
		else
		{
			std::cout << "Error with the opening of the file !" << std::endl;
		}
}

double BitcoinExchange::Verification_date_limite(const std::string &date) 
{
	std::map<std::string, double>::iterator it = _tab.lower_bound(date);

	if (it->first != date && it != _tab.begin()) {
		--it;
	}

	if (it != _tab.end()) {
		return it->second;
	} else if (!_tab.empty()) {
		return it->second;
	}

	return -1.0;
}

void BitcoinExchange::Open_txt(const std::string &filename)
{
	std::ifstream flux(filename.c_str());
	if (flux)
	{
		std::string line;
		std::getline(flux, line);
		while (std::getline(flux, line))
		{
			std::istringstream iss(line);
			std::string date;
			std::string delimiter;
			double value;
			if (!(iss >> date >> delimiter >> value))
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			if (!Verification_date(date))
			{
				std::cout << "Error on the date => " << date << std::endl;
				continue;
			}
			if (value < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			if (value > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			double exchangeRate = Verification_date_limite(date);
			if (exchangeRate == -1.0) 
			{
				std::cout << "Error: No exchange rate available for date => " << date << std::endl;
				continue;
			}

		std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
		}
	}
	else
	{
		std::cout << "Error with the opening of the file !" << std::endl;
	}
}

int	BitcoinExchange::Verification_date(const std::string &date)
{
	std::string::size_type del1 = date.find('-');
	std::string::size_type del2 = date.rfind('-');

	if (del1 == std::string::npos || del1 == del2)
		return -1;

	std::string year_str = date.substr(0, del1);
	std::string month_str = date.substr(del1 + 1, del2 - del1 - 1);
	std::string day_str = date.substr(del2 + 1);

	int year, month, day;
	std::istringstream year_ss(year_str), month_ss(month_str), day_ss(day_str);

	if (!(year_ss >> year) || !(month_ss >> month) || !(day_ss >> day))
		return -1;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return -1;

	if (month == 4 || month == 6 || month == 9 || month == 11) 
	{
		if (day > 30)
			return -1;
	}
	if (month == 2) 
	{
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
			return -1;
		}
	}

	return 1;
}


const char * BitcoinExchange::ErrorDelimiter::what() const throw ()
{
	return ("The delimiter was not found !");
}

const char * BitcoinExchange::ErrorFile::what() const throw ()
{
	return ("Error with the opening of the file !");
}

const char * BitcoinExchange::ErrorValue::what() const throw ()
{
	return ("Error with the value !");
}