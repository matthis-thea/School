/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:44:38 by haze              #+#    #+#             */
/*   Updated: 2023/12/12 12:13:22 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN
#define SPAN
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <cstddef>
class Span
{
	private:
		std::vector<int>					 _vector;
		std::size_t							_s;
		typedef std::vector<int>::iterator _iterat;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &src);
		Span& operator=(const Span &src);
		~Span();
		void addNumber(int n);
		void Bigsize(_iterat begin, _iterat end);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		std::size_t Get_size() const;
		class Full : public std::exception
		{
			public: 
			virtual const char *what() const throw();
		};
		class Small : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};
#endif