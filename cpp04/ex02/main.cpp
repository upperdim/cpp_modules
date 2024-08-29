/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:57:40 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 04:44:08 by tunsal           ###   ########.fr       */
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

	printHeader("Subject PDF tests");
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j; // should not create a leak
		delete i;
	}

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
		// Create and add ideas to Luna
		Cat *luna = new Cat();
		luna->getBrain().addIdea("Lay in the sun");
		luna->getBrain().addIdea("Scratch the couch");
		luna->getBrain().addIdea("Sit with humans");
		luna->getBrain().addIdea("Make biscuits");
		luna->getBrain().addIdea("Inspect delivery boxes");
		luna->getBrain().addIdea("Kekekek birds");
		luna->getBrain().addIdea("Request boiled chicken");

		// Copy Luna to Mia & print ideas
		Cat *mia  = new Cat(*luna);
		std::cout << "Ideas of Mia:" << std::endl;
		mia->getBrain().printIdeas();
		
		// Add new idea to Luna & print
		std::cout << std::endl << "Added a new idea to Luna" << std::endl;
		luna->getBrain().addIdea("Pretend you are not a drone for the Chinese government");
		std::cout << "Ideas of Luna:" << std::endl;
		luna->getBrain().printIdeas();
		
		// Print ideas of Mia
		std::cout << std::endl << "Ideas of Mia:" << std::endl;
		mia->getBrain().printIdeas();

		delete luna;
		delete mia;
	}
	
	printHeader("Deep copy test Dog");
	{
		// Create and add ideas to Luna
		Dog *luna = new Dog();
		luna->getBrain().addIdea("Lay in the sun");
		luna->getBrain().addIdea("Scratch the couch");
		luna->getBrain().addIdea("Sit with humans");
		luna->getBrain().addIdea("Make biscuits");
		luna->getBrain().addIdea("Inspect delivery boxes");
		luna->getBrain().addIdea("Kekekek birds");
		luna->getBrain().addIdea("Request boiled chicken");

		// Copy Luna to Mia & print ideas
		Dog *mia  = new Dog(*luna);
		std::cout << "Ideas of Mia:" << std::endl;
		mia->getBrain().printIdeas();
		
		// Add new idea to Luna & print
		std::cout << std::endl << "Added a new idea to Luna" << std::endl;
		luna->getBrain().addIdea("Pretend you are not a drone for the Chinese government");
		std::cout << "Ideas of Luna:" << std::endl;
		luna->getBrain().printIdeas();
		
		// Print ideas of Mia
		std::cout << std::endl << "Ideas of Mia:" << std::endl;
		mia->getBrain().printIdeas();

		delete luna;
		delete mia;
	}

	return 0;
}
