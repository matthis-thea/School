/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thib <thib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:12:19 by thib              #+#    #+#             */
/*   Updated: 2023/11/17 18:19:22 by thib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_H
# define AFORM_CLASS_H
#pragma once
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	public:
		AForm(void);
		AForm(std::string name, const int gradeToSign, const int _gradeToExec, std::string target);
		virtual ~AForm(void);
		AForm(const AForm &src);

		std::string getName() const;
		std::string getTarget() const;
		bool getSigned()const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat *b);
		virtual void execute(Bureaucrat const & executor) const = 0;

		AForm &operator=( AForm const & hrs);

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

	private:
		const std::string	_name;
		bool					_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
		std::string 		_target;
};
std::ostream	&operator<<(std::ostream &o, AForm *a);
#endif
