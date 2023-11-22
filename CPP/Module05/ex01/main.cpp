/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:19:55 by haze              #+#    #+#             */
/*   Updated: 2023/11/21 14:34:44 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

    try
	{
		Bureaucrat bureaucrat(9, "Louis");
        Form form(10, "Contrat banque", 5);
        form.beSigned(bureaucrat);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
        bureaucrat.signForm(form);
    } 
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
    return 1;
}