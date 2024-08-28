/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:54:09 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 00:36:28 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat created" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat & from) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = from; // calls = operator overload
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(Cat const & rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
		this->_brain = rhs._brain;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

Brain& Cat::getBrain() {
	return *(this->_brain);
}
