/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:31:58 by haze              #+#    #+#             */
/*   Updated: 2023/11/24 14:32:00 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H
#pragma once
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);

		void incrementGrade(int i);
		void decrementGrade(int i);
		int getGrade() const;
		std::string getName() const;
		void signForm(AForm *f);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		Bureaucrat &operator=( Bureaucrat const & hrs);
	private:
		const std::string 	_name;
		int 				_grade;

		void setGrade(int grade);
};
std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);
#endif
