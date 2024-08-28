/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:46:45 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/26 15:21:48 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog created" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog & from) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = from; // calls = operator overload
}

Dog::~Dog() {
	std::cout << "Dog destroyed" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(Dog const & rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}


void Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}

Brain& Dog::getBrain() {
	return *(this->_brain);
}
