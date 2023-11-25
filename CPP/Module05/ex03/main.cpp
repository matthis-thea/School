/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:32:10 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 15:06:41 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "----------------SHRUBBERY TEST-------------" << std::endl;
	Bureaucrat bureaucrat3(1, "Leo");
	ShrubberyCreationForm rubberry("ANtoine");
	bureaucrat3.signForm(rubberry);
	bureaucrat3.executeForm(rubberry);
	std::cout << "----------------INTERN TEST-------------" << std::endl;
	Intern *intern = new Intern();
	AForm *other = intern->makeForm("PresidentialPardonForm", "Lucien");
	AForm *other2 = intern->makeForm("RobotomyRequestForm", "Kalix");
	std::cout << *other << std::endl;
	std::cout << *other2 << std::endl;
	bureaucrat3.signForm(*other);
	bureaucrat3.executeForm(*other);
	delete intern;
}
