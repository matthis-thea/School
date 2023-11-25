/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:50:14 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 11:42:59 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main()
{
	Data *data = new Data;
	data->name = "Matthis";
	data->number = 42;

	uintptr_t data_ptr = serialize(data);
	std::cout << "Serialize 		:" << data_ptr << std::endl;
	Data *data_dese = deserialize(data_ptr);
	std::cout << "Deserialize			:" << data_dese << std::endl;
	std::cout << "Deserialize			:" << data_dese->name << std::endl;
	std::cout << "Deserialize			:" << data_dese->number << std::endl;
}