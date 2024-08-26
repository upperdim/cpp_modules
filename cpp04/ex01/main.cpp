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

int main() {
	// Subject PDF test
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // should not create a leak
	delete i;

	// Create animals
	Animal *animals[NUM_ANIMALS];
	
	for (int i = 0; i < NUM_ANIMALS; ++i) {
		if (i < NUM_ANIMALS / 2) {
			animals[i] = new Cat();
		} else {
			animals[i] = new Dog();
		}
	}	

	
	
	// Delete animals
	for (int i = 0; i < NUM_ANIMALS; ++i) {
		delete animals[i];
	}

	return 0;
}
