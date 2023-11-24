/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:50:14 by haze              #+#    #+#             */
/*   Updated: 2023/11/24 16:57:31 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int main()
{
	Data *data = new Data;
	data->name = "Matthis";
	data->number = 42;

	uintptr_t data_ptr = serialize(data);
	std::cout << "Raw Data			:" << data_ptr << std::endl;
	Data *data_dese = deserialize(data_ptr);
	std::cout << "Raw Data			:" << data_dese->name << std::endl;
	std::cout << "Raw Data			:" << data_dese->number << std::endl;
}