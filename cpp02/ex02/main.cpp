/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:24:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/24 16:28:39 by tunsal           ###   ########.fr       */
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

	printHeader("Comparison");
	{
		Fixed small1 = Fixed(42.42f);
		Fixed small2 = Fixed(42.42f);
		Fixed big    = Fixed(82);

		std::cout << "small1 == small2: " << (small1 == small2) << std::endl;
		std::cout << "small1 != small2: " << (small1 != small2) << std::endl;
		std::cout << "small1 <= small2: " << (small1 <= small2) << std::endl;
		std::cout << "small1 >= small2: " << (small1 >= small2) << std::endl;
		std::cout << "small1  < small2: " << (small1  < small2) << std::endl;
		std::cout << "small1  > small2: " << (small1  > small2) << std::endl;

		std::cout << "big     > small1: " << (big     > small2) << std::endl;
		std::cout << "big     < small1: " << (big     < small2) << std::endl;
	}

	printHeader("Arithmetic");
	{
		Fixed half    = Fixed(0.5f);
		Fixed oneHalf = Fixed(1.5f);

		std::cout << "oneHalf + half: " << (oneHalf + half) << std::endl;
		std::cout << "oneHalf - half: " << (oneHalf - half) << std::endl;
		std::cout << "oneHalf * half: " << (oneHalf * half) << std::endl;
		std::cout << "oneHalf / half: " << (oneHalf / half) << std::endl;
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
