/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:32:26 by haze              #+#    #+#             */
/*   Updated: 2023/11/24 14:32:27 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ROBOTOMYREQUESTFORM_CLASS_H
# define ROBOTOMYREQUESTFORM_CLASS_H
#pragma once
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#include <fstream>
#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm;

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string name, std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm(void);
		void execute(Bureaucrat const & executor) const;

		RobotomyRequestForm &operator=( RobotomyRequestForm const & hrs);
};
std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm *a);
#endif
