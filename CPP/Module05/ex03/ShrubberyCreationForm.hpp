/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thib <thib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:05:27 by tserdet           #+#    #+#             */
/*   Updated: 2023/11/17 18:19:34 by thib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_H
# define SHRUBBERYCREATIONFORM_CLASS_H
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

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string name, std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		~ShrubberyCreationForm(void);
		void execute(Bureaucrat const & executor) const;

		ShrubberyCreationForm &operator=( ShrubberyCreationForm const & hrs);
};
std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a);
#endif
