/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:11:11 by haze              #+#    #+#             */
/*   Updated: 2023/09/03 13:32:07 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL
#define HARL
#include <iostream>
#include <string>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

class Harl
{
	public:
		void	complain(std::string level);
		Harl(void);
		~Harl(void);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void 	error(void);
};
typedef void (Harl::*f_ptr) (void);
#endif