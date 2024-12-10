/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:50:11 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 19:28:03 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

// T must support + operator, << stream and cast from size_t
template <typename T>
void test() {
	Array<T> a1;
	std::cout << "a1 size = " << a1.size() << std::endl << std::endl;

	Array<T> a2(5);
	std::cout << "Populating a2..." << std::endl;
	for (size_t i= 0; i < 5; ++i) {
		a2[i] = i + 1.1;
		std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
	}
	
	std::cout << "Copying to a3..." << std::endl;
	Array<T> a3 = a2;
	
	std::cout << "Modifying a3..." << std::endl;
	a3[0] = -123;

	std::cout << "a2 = ";
	for (size_t i = 0; i < 5; ++i) {
		std::cout << a2[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "a3 = ";
	for (size_t i = 0; i < 5; ++i) {
		std::cout << a3[i] << " ";
	}
	std::cout << std::endl;

	try {
		std::cout << "Accessing out of bounds..." << std::endl;
		T i = a2[999];
		(void) i;
	} catch (std::exception& e) {
		std::cout << "Catched exception: " << e.what() << std::endl;
	}
}



int main() {
	test<int>();   // test with ints
	test<float>(); // test with floats
}
