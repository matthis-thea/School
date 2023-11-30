/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Function.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:05:38 by haze              #+#    #+#             */
/*   Updated: 2023/11/30 09:07:49 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FUNCTION_CLASS
#define FUNCTION_CLASS
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif