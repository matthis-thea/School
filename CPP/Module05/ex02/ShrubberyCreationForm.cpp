/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:08:22 by haze              #+#    #+#             */
/*   Updated: 2023/11/21 16:13:08 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm(25, "ShrubberyCreationForm", 5), _target("louis")
{
	std::cout << "ShrubberyCreationForm constructor was created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(25, "ShrubberyCreationForm", 5), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor was created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src): AForm(src), _target(src._target)
{
	std::cout << "Copy ShrubberyCreationForm constructor was created" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	(void) src;
	std::cout << "ShrubberyCreationForm surchage constructor was created" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm deconstructor was created" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->GetGradeExecute())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream file("_shrubbery");
		file << "                      ___" << std::endl;
		file << "                _,-'\"\"   \"\"\"\"`--." << std::endl;
		file << "             ,-'          __,,-- \\" << std::endl;
		file << "           ,\'    __,--\"\"\"\"dF      )" << std::endl;
		file << "          /   .-\"Hb_,--\"\"dF      /" << std::endl;
		file << "        ,\'       _Hb ___dF\"-._,-'" << std::endl;
		file << "      ,'      _,-\"\"\"\"   \"\"--..__" << std::endl;
		file << "     (     ,-'                  `." << std::endl;
		file << "      `._,'     _   _             ;" << std::endl;
		file << "       ,'     ,' `-'Hb-.___..._,-'" << std::endl;
		file << "       \\    ,'\"Hb.-\'HH`-.dHF\"" << std::endl;
		file << "        `--\'   \"Hb  HH  dF\"" << std::endl;
		file << "                \"Hb HH dF" << std::endl;
		file << "                 \"HbHHdF" << std::endl;
		file << "                  |HHHF" << std::endl;
		file << "                  |HHH|" << std::endl;
		file << "                  |HHH|" << std::endl;
		file << "                  |HHH|" << std::endl;
		file << "                  |HHH|" << std::endl;
		file << "                  dHHHb" << std::endl;
		file << "                .dFd|bHb.               o" << std::endl;
		file << "      o       .dHFdH|HbTHb.          o /" << std::endl;
		file << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__Krogg  Y" << std::endl;
		file << "##########################################" << std::endl;
		file.close();
	}
}