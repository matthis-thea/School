/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:19:55 by haze              #+#    #+#             */
/*   Updated: 2023/11/20 10:11:52 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bureaucrat;
		Bureaucrat bureaucrat_two(1, "Louis");
		std::cout << bureaucrat << std::endl;
		bureaucrat.dec_grade();
		std::cout << bureaucrat << std::endl;
		std::cout << bureaucrat_two << std::endl;
		bureaucrat_two.inc_grade();
		std::cout << bureaucrat_two << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}