/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:06:53 by haze              #+#    #+#             */
/*   Updated: 2023/12/14 14:58:35 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << " Top de la stack" << std::endl;
	mstack.pop();
	std::cout << mstack.size() << " Taille de la stack" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(73);
	mstack.push(37);
	mstack.push(7374);
	mstack.push(77);
	mstack.push(273);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "Reverse" << std::endl;
	MutantStack<int>::reverse_iterator reverse_it = mstack.rbegin();
	MutantStack<int>::reverse_iterator reverse_ite = mstack.rend();
	++reverse_it;
	--reverse_it;
	while (reverse_it != reverse_ite)
	{
		std::cout << *reverse_it << std::endl;
		++reverse_it;
	}
	std::cout << "List" << std::endl << std::endl;
	std::list<int> listt;
	listt.push_back(5);
	listt.push_back(17);
	std::cout << listt.back() << " Top de la stack" << std::endl;
	listt.pop_back();
	std::cout << listt.size() << " Taille de la stack" << std::endl;
	listt.push_back(3);
	listt.push_back(5);
	listt.push_back(73);
	listt.push_back(37);
	listt.push_back(7374);
	listt.push_back(77);
	listt.push_back(273);
	listt.push_back(0);
	std::list<int>::iterator lit = listt.begin();
	std::list<int>::iterator lite = listt.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}
	std::list<int> ls(listt);

	std::cout << "Reverse" << std::endl;
	std::list<int>::reverse_iterator reverse_lit = listt.rbegin();
	std::list<int>::reverse_iterator reverse_lite = listt.rend();
	++reverse_lit;
	--reverse_lit;
	while (reverse_lit != reverse_lite)
	{
		std::cout << *reverse_lit << std::endl;
		++reverse_lit;
	}
	return 0;
}