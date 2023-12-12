/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:54:51 by haze              #+#    #+#             */
/*   Updated: 2023/12/12 12:13:48 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n): _s(n) {}

Span::Span(const Span& src) : _vector(src._vector), _s(src._s) 
{
	*this = src;
}


Span& Span::operator=(const Span& src) 
{
	if (this == &src) 
		return *this;

	this->_s = src._s;
	this->_vector = src._vector;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (this->_vector.size() == this->_s)
		throw Span::Full();
	else
		this->_vector.push_back(n);
}

void Span::Bigsize(_iterat begin, _iterat end) 
{
	if (this->_vector.size() + std::distance(begin, end) > this->_s )
	{
		throw Span::Full();
	}
	this->_vector.insert(this->_vector.end(), begin, end);
}

unsigned int Span::shortestSpan() const 
{
	if (this->_s <= 1 || this->_vector.size() <= 1)
		throw Span::Small();
	std::vector<int> copy(this->_vector);
	std::sort(copy.begin(), copy.end());
	int ret = *(copy.begin() + 1) - *copy.begin();
	for (_iterat it = copy.begin(); it != copy.end() - 1; ++it) 
	{
		if(*(it + 1) - *it < ret)
			ret = *(it + 1) - *it;
	}
	return (ret);
}

unsigned int Span::longestSpan() const
{
	if (this->_s <= 1 || this->_vector.size() <= 1)
		throw Span::Small();
	return *std::max_element(this->_vector.begin(), this->_vector.end()) - *std::min_element(this->_vector.begin(), this->_vector.end());
}

std::size_t Span::Get_size() const
{
	return this->_s;
}

const char* Span::Full::what() const throw() {
	return "The Span is full";
}

const char* Span::Small::what() const throw() {
	return "The span is too small";
}