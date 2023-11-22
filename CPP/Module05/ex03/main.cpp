/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thib <thib@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:55 by thib              #+#    #+#             */
/*   Updated: 2023/11/17 18:31:28 by thib             ###   ########.fr       */
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
	std::cout << GRN << "----------------SHRUBBERY TEST-------------" << NC << std::endl;
	Bureaucrat *a = new Bureaucrat(1);
	AForm *b = new ShrubberyCreationForm("SHRUBBERY", "file");
	std::cout << b << std::endl;
	std::cout << a << std::endl;
	a->signForm(b);
	b->execute(*a);
	std::cout << b << std::endl;
	std::cout << GRN<<"----------------ROBOTOMY TEST-------------" <<NC<< std::endl;
	Bureaucrat *c = new Bureaucrat(1);
	AForm *d = new RobotomyRequestForm("ROBOTOMY", "Popeye");
	std::cout << d << std::endl;
	std::cout << c << std::endl;
	c->signForm(d);
	d->execute(*c);
	d->execute(*c);
	d->execute(*c);
	d->execute(*c);
	std::cout << d << std::endl;
	std::cout << GRN << "----------------PRESIDENTIAL TEST-------------" << NC << std::endl;
	Bureaucrat *e = new Bureaucrat(1);
	AForm *f = new PresidentialPardonForm("PRESIDENTIAL", "Mickey");
	std::cout << f << std::endl;
	std::cout << e << std::endl;
	e->signForm(f);
	f->execute(*e);
	std::cout << f << std::endl;
	std::cout << GRN << "----------------INTERN TEST-------------" << NC << std::endl;
	Intern *g = new Intern();
	AForm *h = g->makeForm("PresidentialPardonForm", "Bender");
	if (h)
		a->signForm(h);
	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
	delete g;
}
