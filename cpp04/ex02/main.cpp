/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:57:40 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 02:51:08 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
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
	// Not possible anymore, AAnimal is abstract class
	// const AAnimal* animal = new AAnimal();
	// delete animal;

	printHeader("Array test");
	{
		AAnimal *animals[NUM_ANIMALS];
		
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

	printHeader("Deep copy test Cat");
	{
		Cat *luna = new Cat();
		
		luna->getBrain().addIdea("Lay in the sun");
		luna->getBrain().addIdea("Scratch the couch");
		luna->getBrain().addIdea("Sit with humans");
		luna->getBrain().addIdea("Make biscuits");
		luna->getBrain().addIdea("Inspect delivery boxes");
		luna->getBrain().addIdea("Kekekek birds");
		luna->getBrain().addIdea("Pretend you are not a drone for the Chinese government");
		luna->getBrain().addIdea("Request boiled chicken");

		Cat *mia  = new Cat(*luna);
		
		mia->getBrain().printIdeas();

		delete luna;
		delete mia;
	}

	printHeader("Deep copy test Dog");
	{
		Dog *luna = new Dog();
		
		luna->getBrain().addIdea("Lay in the sun");
		luna->getBrain().addIdea("Scratch the couch");
		luna->getBrain().addIdea("Sit with humans");
		luna->getBrain().addIdea("Make biscuits");
		luna->getBrain().addIdea("Inspect delivery boxes");
		luna->getBrain().addIdea("Kekekek birds");
		luna->getBrain().addIdea("Pretend you are not a drone for the Chinese government");
		luna->getBrain().addIdea("Request boiled chicken");

		Dog *mia  = new Dog(*luna);
		
		mia->getBrain().printIdeas();

		delete luna;
		delete mia;
	}

	return 0;
}
