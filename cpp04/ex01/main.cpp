/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:57:40 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/26 15:45:13 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define NUM_ANIMALS 4

static void printHeader(std::string header) {
	std::cout                                                   << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << header                                         << std::endl;
	std::cout << "============================================" << std::endl;
}

int main() {
	printHeader("Subject PDF tests");
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j; // should not create a leak
		delete i;
	}

	printHeader("Array test");
	{
		Animal *animals[NUM_ANIMALS];
		
		// Create animals
		for (int i = 0; i < NUM_ANIMALS; ++i) {
			if (i < NUM_ANIMALS / 2) {
				animals[i] = new Cat();
			} else {
				animals[i] = new Dog();
			}
		}	

		for (int i = 0; i < NUM_ANIMALS; ++i) {
			animals[i]->makeSound();
		}
		
		for (int i = 0; i < NUM_ANIMALS; ++i) {
			delete animals[i];
		}
	}

	return 0;
}
