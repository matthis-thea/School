/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haze <haze@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:12:46 by haze              #+#    #+#             */
/*   Updated: 2023/12/17 16:13:21 by haze             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " \"OPERATION\"\n";
		return 1;
	}
	
	try {
		int res = RPN::ResolveExpression(argv[1]);
		std::cout << "Result: " << res << '\n';
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << '\n';
		return 1;
	}
	
	return 0;
}