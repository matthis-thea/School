/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileA.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 10:38:42 by mthea             #+#    #+#             */
/*   Updated: 2023/09/01 19:20:05 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEA
#define FILEA

#include <iostream>
#include <fstream>
#include <string>

class File
{
	public:
		File(void);
		~File(void);
		int file_replace(std::string file, std::string f_arg, std::string s_arg);
};
#endif
