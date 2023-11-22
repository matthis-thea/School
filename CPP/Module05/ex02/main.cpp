/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:12:55 by haze              #+#    #+#             */
/*   Updated: 2023/11/21 16:13:49 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat(4, "Louis");
	PresidentialPardonForm presidentail("Philippe");
	RobotomyRequestForm robotomy("Jacques");
	ShrubberyCreationForm rubbery("rubbery");
	bureaucrat.signForm(presidentail);
	bureaucrat.executeForm(presidentail);
	bureaucrat.signForm(robotomy);
	bureaucrat.executeForm(robotomy);
	bureaucrat.signForm(rubbery);
	bureaucrat.executeForm(rubbery);
}