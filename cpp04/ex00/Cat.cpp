/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:54:09 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/24 13:54:09 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat created" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat & from) : Animal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = from; // calls = operator overload
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
}

Cat &Cat::operator=(Cat const & rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
