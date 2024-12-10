/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:18:25 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 04:47:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

void vectorTests() {
	std::vector<int> vec;
	for (int i = 0; i < 5; ++i) {
		vec.push_back(i);
	}
    std::vector<int>::iterator vecIt = easyfind(vec, 3);
	std::cout << "Found: " << *vecIt << std::endl;
	
	try {
		vecIt = easyfind(vec, 100);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void listTests() {
	std::list<int> lst;
	for (int i = 0; i < 5; ++i) {
		lst.push_back(i);
	}
	std::list<int>::iterator lstIt = easyfind(lst, 3);
	std::cout << "Found: " << *lstIt << std::endl;
	
	try {
		lstIt = easyfind(lst, 100);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main() {
    vectorTests();
	listTests();
}
