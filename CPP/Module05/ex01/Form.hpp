/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:42:18 by haze              #+#    #+#             */
/*   Updated: 2023/11/21 14:42:14 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM
#define FORM
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool			_Issigned;
		const int 		_grade_sign;
		const int 		_grade_execute;
	public:
		Form(void);
		Form(const int grade_sign, const std::string name, const int grade_exec);
		Form(const Form &src);
		Form &operator=(const Form &src);
		~Form(void);
		void 		beSigned(const Bureaucrat &src);
		bool        GetSigned() const;
		int         GetGradeSign() const;
		int         GetGradeExecute() const;
		std::string GetName(void) const;
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
};
std::ostream  &operator<<( std::ostream &o, const Form &src);
#endif 