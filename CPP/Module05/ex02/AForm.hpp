/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:42:18 by haze              #+#    #+#             */
/*   Updated: 2023/11/25 14:26:26 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM
#define AFORM
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		const std::string _target;
		bool			_Issigned;
		const int 		_grade_sign;
		const int 		_grade_execute;
	public:
		AForm(void);
		AForm(const int grade_sign, const std::string name, const std::string target , const int grade_exec);
		AForm(const AForm &src);
		AForm &operator=(const AForm &src);
		~AForm(void);
		void 		beSigned(const Bureaucrat &src);
		bool        GetSigned() const;
		int         GetGradeSign() const;
		int         GetGradeExecute() const;
		virtual void execute(const Bureaucrat &executor) const = 0;
		std::string GetName(void) const;
		std::string GetTarget(void) const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NotExecute : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class NotSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};	
};
std::ostream  &operator<<( std::ostream &o, const AForm &src);
#endif 