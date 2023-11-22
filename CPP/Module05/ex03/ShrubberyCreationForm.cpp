/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thib <thib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:05:25 by tserdet           #+#    #+#             */
/*   Updated: 2023/11/17 13:12:16 by thib             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("DefaultShrubberyCreationForm", 145, 137, "Default")
{
	std::cout <<CYN<< "Default ShrubberyCreationForm constructor called" <<NC<< std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target): AForm(name, 145, 137, target)
{
	std::cout <<CYN<< name <<" AForm ShrubberyCreationForm constructor called" <<NC<< std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src) : AForm(src)
{
	std::cout <<CYN<< "Copy ShrubberyCreationForm constructor called" <<NC<< std::endl;
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout <<CYN<< "Default ShrubberyCreationForm destructor called" <<NC<< std::endl;
	return;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() < this->getGradeExec() && this->getSigned() == 1)
	{
		std::cout <<"Bureaucrat "<< executor.getName() <<  " executed ShrubberyCreationForm" << std::endl;
		std::ofstream ofs (this->getTarget().c_str(), std::ofstream::out);

		for (int i = 0; i < 5; i++)
			{
				ofs <<
				"         v" << std::endl <<
				"        >X<" << std::endl <<
				"         A" << std::endl <<
				"        d$b" << std::endl <<
				"      .d\\$$b." << std::endl <<
				"    .d$i$$\\$$b." << std::endl <<
				"       d$$@b" << std::endl <<
				"      d\\$$$ib" << std::endl <<
				"    .d$$$\\$$$b" << std::endl <<
				"  .d$$@$$$$\\$$ib." << std::endl <<
				"      d$$i$$b" << std::endl <<
				"     d\\$$$$@$b" << std::endl <<
				"  .d$@$$\\$$$$$@b." << std::endl <<
				".d$$$$i$$$\\$$$$$$b." << std::endl <<
				"        ###" << std::endl <<
				"        ###" << std::endl <<
				"        ###" << std::endl <<
			std::endl;
			}
		ofs.close();
	}
	else
		std::cout << "Bureaucrat " << executor.getName() <<  " cannot execute ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm const & hrs)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &hrs)
		return *this;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, ShrubberyCreationForm *a)
{
	o << "AForm " << a->getName() << ", signed: " << a->getSigned()
		<< ", grade to sign: " << a->getGradeSign() << ", grade to exec: " << a->getGradeExec()<< ", target: "
		<< a->getTarget() << std::endl;
	return (o);
}
