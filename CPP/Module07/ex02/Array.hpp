/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:09:06 by haze              #+#    #+#             */
/*   Updated: 2023/12/08 13:22:47 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY
#define ARRAY

#include <exception>
#include <iostream>
#include <string>

template <typename T>
class Array 
{
	public:
		Array(): array(NULL), sizee(0) {};
		Array(unsigned int n): array(new T[n]), sizee(n) {};
		Array(const Array& src): array(NULL) {*this = src;}
    	Array& operator=(const Array& src)
		{
			if (this == &src)
				return *this;
			if (this->sizee != src.sizee)
			{
				if (this->array != NULL) 
					delete[] this->array;
				this->array = new T[src.sizee];
				this->sizee = src.size();
			}
			for (unsigned int i = 0; i < this->sizee; ++i)
			{
				this->array[i] = src[i];
			}
			return *this;
		}
		~Array() { delete[] this->array;}
		T& operator[](unsigned int index) 
		{
			if (index >= this->sizee) 
				throw Array::ErrorInSize();
			// else if (index < 0)
			// 	throw Array::ErrorInSize();
			else
				return this->array[index];
		}
		const T& operator[](unsigned int index) const
		{
			if (index >= this->sizee) 
				throw Array::ErrorInSize();
			// else if (index < 0)
			// 	throw Array::ErrorInSize();
			else
				return this->array[index];
		}
		unsigned int size() const { return this->sizee;}
		class ErrorInSize : public std::exception 
		{
			public: virtual const char* what() const throw()
			{
				return "The size are invalid";
			}
		};
	private:
		T *array;
		unsigned int sizee;
};

#endif