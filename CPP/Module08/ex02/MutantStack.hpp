/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:45:39 by haze              #+#    #+#             */
/*   Updated: 2023/12/14 14:58:26 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK
#define MUTANTSTACK
#include <stack>
#include <deque>
#include <iostream>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{	
	public:
		MutantStack()
		{}
		MutantStack(const MutantStack &src)
		{
			*this = src;
		}
		MutantStack &operator=(const MutantStack &src)
		{
			if (this == src)
				return *this;
			this->std::stack<T, Container>::operator=(src);
			return *this;
		}
		~MutantStack()
		{

		}
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		typedef typename std::stack<T, Container>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T, Container>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T, Container>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return this->std::stack<T, Container>::c.begin();
		}

		iterator end()
		{
			return this->std::stack<T, Container>::c.end();
		}

		const_iterator begin() const
		{
			return this->std::stack<T, Container>::c.begin();
		}

		const_iterator end() const
		{
			return this->std::stack<T, Container>::c.end();
		}

		reverse_iterator rbegin()
		{
			return this->std::stack<T, Container>::c.rbegin();
		}

		reverse_iterator rend()
		{
			return this->std::stack<T, Container>::c.rend();
		}

		const reverse_iterator rbegin() const 
		{
			return this->std::stack<T, Container>::c.rbegin();
		}

		const reverse_iterator rend() const 
		{
			return this->std::stack<T, Container>::c.rend();
		}
};

#endif