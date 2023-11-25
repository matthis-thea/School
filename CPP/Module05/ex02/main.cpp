/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:12:55 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 14:47:43 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	 try
	{
		std::cout << "------Test pour les presidential---------" << std::endl;
		std::cout << std::endl;
		Bureaucrat bureaucrat(4, "Lois");
		PresidentialPardonForm presidential("Philippe");
		bureaucrat.signForm(presidential);
		bureaucrat.executeForm(presidential);
    } 
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
	try
	{
		std::cout << std::endl << std::endl;
		std::cout << "------Test pour les robotomy---------" << std::endl;
		std::cout << std::endl;
		Bureaucrat bureaucrat2(44, "Louis");
		RobotomyRequestForm robotomy("Jacques");
		bureaucrat2.signForm(robotomy);
		bureaucrat2.executeForm(robotomy);
    } 
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
	try
	{
		std::cout << std::endl << std::endl;
		std::cout << "------Test pour les shruberry---------" << std::endl;
		std::cout << std::endl;
		Bureaucrat bureaucrat3(137, "Leo");
		ShrubberyCreationForm rubberry("ANtoine");
		bureaucrat3.signForm(rubberry);
		bureaucrat3.executeForm(rubberry);
    } 
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
}