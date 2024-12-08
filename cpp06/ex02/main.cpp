/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:51:07 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/08 21:01:58 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// `typeinfo` header is FORBIDDEN
#include <ctime>    // time()
#include <cstdlib>  // rand()
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Randomly instanciate A, B or C, return a Base pointer to the instance
Base * generate(void) {
	int r = std::rand() % 3;
	if      (r == 0) return new A;
	else if (r == 1) return new B;
	else if (r == 2) return new C;
	else             return NULL;
}

// Print what type `p` is
void identify(Base* p) {
	// If dynamic cast fails, it returns 0 in C++98, `nullptr` in C++11 and above
	if (dynamic_cast<A*>(p) != nullptr && dynamic_cast<A*>(p) != 0) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p) != nullptr && dynamic_cast<B*>(p) != 0) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p) != nullptr && dynamic_cast<C*>(p) != 0) {
		std::cout << "C" << std::endl;
	}
}

// Print what type `p` is WITHOUT USING A POINTER
void identify(Base& p) {
	// If dynamic cast fails for reference, it throws `std::bad_cast` exception
	try {
		A& ra = dynamic_cast<A&>(p);
		(void) ra;
		
		std::cout << "A" << std::endl;
	} catch(std::bad_cast) {}

	try {
		B& rb = dynamic_cast<B&>(p);
		(void) rb;
		
		std::cout << "B" << std::endl;
	} catch(std::bad_cast) {}

	try {
		C& rc = dynamic_cast<C&>(p);
		(void) rc;
				
		std::cout << "C" << std::endl;
	} catch(std::bad_cast) {}
}

int main() {
	std::srand(time(NULL));

	for (int i = 0; i < 15; ++i) {
		Base *base = generate();
		if (base == NULL) {
			std::cout << "Error: generate()" << std::endl;
			return EXIT_FAILURE;
		}

		// Identify by pointer
		identify(base);
		
		// Identify by reference
		identify(*base);

		std::cout << std::endl;
	}
}
