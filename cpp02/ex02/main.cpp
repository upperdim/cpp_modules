/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:24:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/24 16:20:44 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept> // invalid_argument
#include <iostream>
#include "Fixed.hpp"

static void printHeader(std::string header) {
	std::cout                                                   << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << header                                         << std::endl;
	std::cout << "============================================" << std::endl;
}

int main() {
	printHeader("Subject PDF tests");
	{
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));
		
		std::cout <<   a   << std::endl;
		std::cout << ++a   << std::endl;
		std::cout <<   a   << std::endl;
		std::cout <<   a++ << std::endl;
		std::cout <<   a   << std::endl;
		
		std::cout <<   b   << std::endl;
		
		std::cout << Fixed::max(a, b) << std::endl;
	}

	printHeader("Division by 0");
	{
		Fixed a = Fixed(123);

		try {
			a / 0;
		} catch(std::invalid_argument const &ex) {
			std::cout << "Catched exception: " << ex.what() << std::endl;
		}
	}
	
	return 0;
}
